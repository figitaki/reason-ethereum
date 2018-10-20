open Rethereum_rlp;

type t = string;

let get = (_, _address) => Account.of_rlp(Rlp.empty);

let set = (state, _address, _account) => state;
