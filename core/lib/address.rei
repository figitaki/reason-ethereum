/**
  Address, 160-bit identifier for Accounts

  @author  Carey Janecka <careyjanecka@gmail.com>
  @created 4/9/18
  */

type t;

/**
  Convert the given string to an Ethereum address. The string is
  read in hexidecimal.

  Raise `Failure "Address.of_string"` if the given string is not a valid
  representation of an address.
 */
let of_string : string => t;

/**
  Render the given address as a hex encoded string.
 */
let to_string : t => string;

