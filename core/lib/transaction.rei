/**
module Signature = {
  type t = (Int256.t, Int256.t, int);  // (r, s, v)
};
*/

type t;

/**
  Tuple consisting of amount of gas used, set of logs,
  a bloom filter of log info, and the status code.
 */
type receipt = (Int256.t, Int256.t, string, Int256.t); 
