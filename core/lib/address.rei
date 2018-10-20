/**
  Address, 160-bit identifier for Accounts

  @author  Carey Janecka <careyjanecka@gmail.com>
  @created 4/9/18
  */
open Rethereum_rlp;

/**
Abstract type for ethereum address.
*/
type t;

let is_empty: t => bool;

/**
Convert the given string to an Ethereum address. The string is
read in hexidecimal.

Raise `Failure "Address.of_string"` if the given string is not a valid
representation of an address.
*/
let of_string: string => t;

/**
Serializes the address as Rlp.
*/
let rlp_of_t: t => Rlp.t;

/**
Render the given address as a hex encoded string.
*/
let to_string: t => string;

let empty: t;
