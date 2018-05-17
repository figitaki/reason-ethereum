/**
  Recursive Length Prefix encoding/decoding

  @author Carey Janecka <careyjanecka@gmail.com>
  @created 5.16.18
 */

open Cryptokit;

type t = 
| String(string)
| List(list(t));

/**
  Represents the Rlp representation of the empty set.
 */
let empty = List([]);

/**
  Returns ture if the Rlp is the empty set.
 */
let is_empty = t => switch (t) {
  | List([]) => true
  | _ => false
  };

/**
  Creates an Rlp consisting of the provided string.
 */
let of_string = s => String(s);

/**
  Creates an Rlp of the passed list.
 */
let of_list = l => List(l);

/**
  If the root element is a list, return the element at
  index. Raises Out_of_bounds if index > length.
 */
let get = (t, i) => switch (t) {
  | List(l) => List.nth(l, i)
  | String(_) => raise(Invalid_argument("Cannot call get on string"))
  };

/**
  Encodeds the Rlp into a byte sequence.
 */
let rec encode = t =>
switch (t) {
  | List(l) => 
  let enc = List.fold_left((acc, item) => acc ++ encode(item), "", l);
  Encoder.encode_length(String.length(enc), 192) ++ enc;
  | String(s) => Encoder.encode_string(s);
  };

/**
  Decodes the byte sequence into Rlp.
 */
let decode = str => {
  let decoded = Decoder.decode(str);
  Some(of_string(decoded))
};

/**
  Converts the Rlp to human readable hexadecimal encoded string.
 */
let to_string = t => 
  encode(t)
  |> transform_string(Hexa.encode());

