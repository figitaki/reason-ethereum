type t = {
  nonce: Int256.t,
  gasPrice: Int256.t,
  gasLimit: Int256.t,
  recipient: option(Address.t),
  value: Int256.t,
  signature: (Int256.t, Int256.t, int),
  init: option(string), 
  data: option(string)
};

type receipt = (Int256.t, Int256.t, string, Int256.t); 
