/**
  Recursive Length Prefix encoding/decoding

  @author Carey Janecka <careyjanecka@gmail.com>
  @created 5.16.18
 */
type t =
  | String(string)
  | List(list(t));

/**
 Represents the Rlp representation of the empty set.
 */
let empty: t;

/**
  Returns ture if the Rlp is the empty set.
 */
let is_empty: t => bool;

/**
  Creates an Rlp consisting of the provided string.
 */
let of_string: string => t;

/**
  Creates an Rlp of the passed list.
  */
let of_list: list(t) => t;

/**
 If the root element is a list, return the element at
 index. Raises Out_of_bounds if index > length.
 */
let get: (t, int) => t;

/**
  Converts the Rlp to human readable hexadecimal encoded string.
 */
let to_string: t => string;

/**
  Encodeds the Rlp into a byte sequence.
 */
let encode: t => string;

/**
  Decodes the byte sequence into Rlp.
 */
let decode: string => option(t);
