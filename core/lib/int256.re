open Rethereum_rlp;

type t = Z.t;

/**
 * Returns a byte sequence of the big endian representation
 * of the scalar.
 */
let to_bits = num => Z.to_bits(num) |> Base.String.rev;

let rlp_of_t = num => to_bits(num) |> Rlp.of_string;

let of_int = num => string_of_int(num);

let zero = Z.zero;

let compare = Z.compare;
