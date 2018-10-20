open Printf;
open Cryptokit;

open Rethereum_crypto;

let hex = str => transform_string(Hexa.encode(), str);

let () = {
  let sk = Secp256k1.random_seckey();
  printf("secret:  %s\n", hex(sk));

  let ctx = Secp256k1.create_context();
  let pk = Secp256k1.(serialize_pubkey(ctx, create_pubkey(ctx, sk)));
  printf("public:  %s\n", hex(pk));

  let tmp_hash = hash_string(Cryptokit.Hash.keccak(256), pk);
  let address = String.sub(tmp_hash, 12, 20);
  printf("address: %s\n", hex(address));
};
