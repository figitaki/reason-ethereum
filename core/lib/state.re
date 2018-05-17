open Rethereum_rlp;

type t = string;

let get = (_, address) => Account.of_rlp(Rlp.empty);

let set = (state, address, account) => state;
