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

let make : unit => t;

let hash : t => Hash.t;

/**
  Returns the storage root of the account's storage trie.
 let storageRoot : t => Trie.t;
 */

/**
  Returns the representation of the account state as Rlp
 */
let rlp_of_t : t => Rlp.t;

/**
  Decodes any well-formed Rlp into an account state object.
 */
let of_rlp : Rlp.t => t;
