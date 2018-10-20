/**
 Ethereum transaction signature.
 Encoded as a tuple of (r, s, v)
 */
open Rethereum_rlp;

module Signature = {
  type t = (int, Int256.t, Int256.t);
  let rlp_of_t = signature => {
    let (v, r, s) = signature;
    [
      Int256.rlp_of_t(r),
      Int256.rlp_of_t(s),
      Rlp.of_string(String.make(1, Char.chr(v))),
    ]
    |> Rlp.of_list;
  };
  /** TODO implement **/;
  /* let of_rlp = rlp => (26, Int256.zero, Int256.zero); */
};

type t = {
  nonce: Int256.t,
  gasPrice: Int256.t,
  gasLimit: Int256.t,
  recipient: Address.t,
  value: Int256.t,
  signature: Signature.t,
  init: string,
  data: string,
};

type receipt = (Int256.t, Int256.t, string, Int256.t);

let rlp_of_t = tx =>
  [
    Int256.rlp_of_t(tx.nonce),
    Int256.rlp_of_t(tx.gasPrice),
    Int256.rlp_of_t(tx.gasLimit),
    Address.rlp_of_t(tx.recipient),
    Int256.rlp_of_t(tx.value),
    Signature.rlp_of_t(tx.signature),
    Rlp.of_string(tx.data),
  ]
  |> Rlp.of_list;

let of_rlp = _rlp => {
  nonce: Int256.zero,
  gasPrice: Int256.zero,
  gasLimit: Int256.zero,
  recipient: Address.empty,
  value: Int256.zero,
  signature: (0, Int256.zero, Int256.zero),
  init: "",
  data: "",
};

let hash = tx => rlp_of_t(tx) |> Rlp.encode |> Hash.from_string;
