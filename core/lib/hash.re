open Cryptokit;

open Rethereum_rlp;

type t = string;

let of_string = s => transform_string(Hexa.decode(), s);

let to_string = t => transform_string(Hexa.encode(), t);

let from_string = s => hash_string(Hash.keccak(256), s);

let compare = (a, b) => String.compare(a, b);

let rlp_of_t = hash => Rlp.of_string(hash);
