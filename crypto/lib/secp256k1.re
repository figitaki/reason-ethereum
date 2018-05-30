open Ctypes;

open Foreign;

module Context = {
  /** Abstract secp256k1_context type */
  type t = ptr(unit);
  let create = foreign("secp256k1_context_create", char @-> returning(ptr(t)));
  let clone = foreign("secp256k1_context_clone", ptr(t) @-> ptr(t));
  let destroy = foreign("secp256k1_context_destroy", ptr(t) @-> void);
};

module Pubkey = {
  type t = ptr(unit);
  let parse =
    foreign(
      "secp256k1_ec_pubkey_parse",
      ptr(Context.t) @-> ptr(t) @-> ptr(uchar) @-> size_t @-> returning(int)
    );
  let serialize =
    foreign(
      "secp256k1_ec_pubkey_serialize",
      ptr(Context.t)
      @-> ptr(char)
      @-> ptr(size_t)
      @-> ptr(t)
      @-> int
      @-> returning(int)
    );
  let to_string = _pubkey =>
    /* create context */
    serialize();
};

let nonce_function =
  ptr(uchar)
  @-> ptr(uchar)
  @-> ptr(uchar)
  @-> ptr(uchar)
  @-> ptr(void)
  @-> uint
  @-> returning(int);

module ECDSA = {
  let verify =
    foreign(
      "secp256k1",
      ptr(Context.t)
      @-> ptr(Signature.t)
      @-> ptr(uchar)
      @-> ptr(Pubkey.t)
      @-> returning(int)
    );
  let sign =
    foreign(
      "secp256k1secp256k1_ecdsa_sign",
      ptr(Context.t)
      @-> ptr(Signature.t)
      @-> ptr(uchar)
      @-> ptr(uchar)
      @-> ptr(uchar)
      @-> funptr(nonce_function)
      @-> ptr(Pubkey.t)
      @-> returning(int)
    );
};

module Signature = {
  type t = ptr(unit);
  let to_string: t => string = signature => serialize(signature);
};

let sign = {
  let ctx = Context.create(Char.chr(1));
  ();
};

let verify = {
  let ctx = allocateContext.create(Char.chr(1));
  let result = ECDSA.verify(ptr(ctx));
  ();
};
