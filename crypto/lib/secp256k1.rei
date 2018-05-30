module type Pubkey = {
  type t;
  let of_string: string => t;
  let to_bits: t => string;
};

module type Signature = {
  type t = (int, string, string);
  let of_string: string => t;
  let to_bits: t => string;
};

let pubkey: string => Pubkey.t;

/** Creaet an ECDSA Signature
 *
 * Returns a signature of the provided message.
 * Params - msg: the 32-byte message hash being signed.
 *          key: a 32-byte secret key
 */
let sign: (~msg: string, ~key: string) => signature;

let recover: (~msg: string, ~v: int, ~r: string, ~s: string) => pubkey;

/** Verify an ECDSA signature.
 *
 * Returns: true: correct signature
 *          false: incorrect or unparseable signature
 */
let verify: (Signature.t, ~msg: string, ~pubkey: Pubkey.t) => bool;
