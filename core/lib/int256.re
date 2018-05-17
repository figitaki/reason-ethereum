open Rethereum_rlp;

type t = string;

let rlp_of_t = num => Rlp.of_string(num);

let of_int = num => string_of_int(num);
