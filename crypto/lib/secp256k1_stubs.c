#include <string.h>

#include <secp256k1.h>
#include <secp256k1_recovery.h>

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/bigarray.h>
#include <caml/custom.h>
#include <caml/fail.h>

/* Accessing the secp256k1_context as part of an OCaml custom block */
#define Context_val(v) (*((secp256k1_context **) Data_custom_val(v)))

void context_destroy(value ctx) {
  secp256k1_context_destroy(Context_val(ctx));
}

static struct custom_operations secp256k1_context_ops = {
  .identifier = "secp256k1_context",
  .finalize = context_destroy,
  .compare = custom_compare_default,
  .compare_ext = custom_compare_ext_default,
  .hash = custom_hash_default,
  .serialize = custom_serialize_default,
  .deserialize = custom_deserialize_default
};

static value alloc_context(secp256k1_context* ctx) {
  value ml_ctx = caml_alloc_custom(&secp256k1_context_ops, sizeof(secp256k1_context *), 0, 1);
  Context_val(ml_ctx) = ctx;
  return ml_ctx;
}

CAMLprim value context_create() {
  CAMLparam0();
  int flags = SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN;
  secp256k1_context* ctx = secp256k1_context_create(flags);
  if (!ctx) caml_failwith("context_create");
  CAMLreturn(alloc_context(ctx));
}

CAMLprim value generate_seckey(value buf) {
  CAMLparam1(buf);
  char *sk = Caml_ba_data_val(buf);
  for (int i = 0; i < 32; i++) {
    sk[i] = i * 24;
  }
  CAMLreturn(Val_int(0));
}

CAMLprim value ec_pubkey_serialize(value ctx, value buf, value pk) {
  size_t size = Caml_ba_array_val(buf)->dim[0];
  unsigned int flags = SECP256K1_EC_UNCOMPRESSED;

  secp256k1_ec_pubkey_serialize(Caml_ba_data_val(ctx),
                                Caml_ba_data_val(buf),
                                &size,
                                Caml_ba_data_val(pk),
                                flags);

  return Val_int(size);
}

CAMLprim value ec_pubkey_create(value ctx, value buf, value sk) {
  return Val_bool(secp256k1_ec_pubkey_create(Caml_ba_data_val(ctx),
                                             Caml_ba_data_val(buf),
                                             Caml_ba_data_val(sk)));
}
 
CAMLprim value ec_sign_recoverable(value ctx, value buf, value seckey, value msg) {
  secp256k1_ecdsa_recoverable_signature sig;
  int res = secp256k1_ecdsa_sign_recoverable(Caml_ba_data_val(ctx),
                                          &sig,
                                          Caml_ba_data_val(msg),
                                          Caml_ba_data_val(seckey),
                                          NULL, NULL);
  int recid;
  secp256k1_ecdsa_recoverable_signature_serialize_compact(Caml_ba_data_val(ctx),
                                                       Caml_ba_data_val(buf),
                                                       &recid,
                                                       &sig);
  char *sig_ser = Caml_ba_data_val(buf);
  sig_ser[64] = recid;
  return Val_bool(res);
}

