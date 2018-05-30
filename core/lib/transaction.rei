/**
module Signature = {
  type t = (Int256.t, Int256.t, int);  // (r, s, v)
};
*/
open Rethereum_rlp;

type t;

/**
  Tuple consisting of amount of gas used, set of logs,
  a bloom filter of log info, and the status code.
 */
type receipt = (Int256.t, Int256.t, string, Int256.t);

let rlp_of_t: t => Rlp.t;

let of_rlp: Rlp.t => t;

let hash: t => Hash.t;
