/**
  Account State as defined in the yellow paper.

  @author  Carey Janecka <careyjanecka@gmail.com
  @created 5/9/18
 */
open Rethereum_rlp;

type t = {
  nonce: Int256.t,
  balance: Int256.t,
  storageRoot: Hash.t,
  codeHash: Hash.t,
};

let make = () => {
  nonce: Int256.zero,
  balance: Int256.zero,
  storageRoot: Hash.from_string(""),
  codeHash: Hash.from_string(""),
};

let is_empty = account => Int256.compare(account.nonce, Int256.zero) == 0;

/**
  Returns the representation of the account state as Rlp
 */
let rlp_of_t = account =>
  [
    Int256.rlp_of_t(account.nonce),
    Int256.rlp_of_t(account.balance),
    Hash.rlp_of_t(account.storageRoot),
    Hash.rlp_of_t(account.codeHash),
  ]
  |> Rlp.of_list;

let hash = account => rlp_of_t(account) |> Rlp.encode |> Hash.from_string;

/**
  Decodes any well-formed Rlp into an account state object.
  TODO implement, this is placeholder
*/
let of_rlp = _rlp => {
  nonce: Int256.zero,
  balance: Int256.zero,
  storageRoot: Hash.from_string(""),
  codeHash: Hash.from_string(""),
};
