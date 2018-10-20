open Printf;
open Rethereum_core;

let () = {
  let my_account = Account.make();
  let my_hash = Account.hash(my_account);
  let str = Hash.to_string(my_hash);
  printf("Empty account: %s\n", str);
};
