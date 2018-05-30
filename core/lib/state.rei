/** The abstract type of world state */
type t;

let get: (t, Address.t) => Account.t;

let set: (t, Address.t, Account.t) => t;
