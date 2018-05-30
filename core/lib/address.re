open Rethereum_rlp;
open Cryptokit;

type t =
  | String(string)
  | Empty;

exception InvalidAddress(string);

let empty = Empty;

let is_empty = address =>
  switch address {
  | Empty => true
  | String(_) => false
  };

let of_string = s =>
  switch (String.length(s)) {
  | 0 => Empty
  | 160 => String(transform_string(Hexa.decode(), s))
  | _ => raise(InvalidAddress("Invalid argument s"))
  };

let to_string = t =>
  switch t {
  | String(s) => transform_string(Hexa.encode(), s)
  | Empty => ""
  };

let rlp_of_t = address =>
  switch address {
  | String(s) => Rlp.of_string(s)
  | Empty => Rlp.empty
  };
