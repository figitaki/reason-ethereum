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
  codeHash: Hash.t
};

/**
  Returns the storage root of the account's storage trie.
 let storageRoot : t => string;// Trie.t;
 */

let make = () => {
  nonce: Int256.of_int(0),
  balance: Int256.of_int(0),
  storageRoot: Hash.from_string(""),
  codeHash: Hash.from_string("")
};

/**
  Returns the representation of the account state as Rlp
 */
let rlp_of_t = account =>
  [
    Int256.rlp_of_t(account.nonce),
    Int256.rlp_of_t(account.balance),
    Hash.rlp_of_t(account.storageRoot),
    Hash.rlp_of_t(account.codeHash)
  ]
  |> Rlp.of_list;


let hash = account =>
  rlp_of_t(account)
  |> Rlp.encode
  |> Hash.from_string;

/**
  Decodes any well-formed Rlp into an account state object.
*/
let of_rlp = rlp => {
  nonce: "0",
  balance: "0",
  storageRoot: Hash.from_string(""),
  codeHash: Hash.from_string("")
};
