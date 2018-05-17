type t = {
  parentHash: Hash.t,
  ommersHash: Hash.t,
  beneficiary: Address.t,
  stateRoot: Hash.t,
  transactionRoot: Hash.t,
  receiptsRoot: Hash.t,
  difficulty: Int256.t,
  number: Int256.t,
  gasLimit: Int256.t,
  gasUsed: Int256.t,
  timestamp: Int256.t,
  extraData: string,
  mixHash: Hash.t,
  nonce: Int64.t
};

/*
  logsBloom: LogFilter.t,
  */

/**
  Validates the block header, returns true if valid, otherwise false.
 */
let valid = header => true;
/*
type t = {
  parentHash: Hash.t,
  ommersHash: Hash.t,
  beneficiary: Address.t,
  stateRoot: Hash.t,
  transactionRoot: Hash.t,
  receiptsRoot: Hash.t,
  logsBloom: LogFilter.t,
  difficulty: Int256.t,
  number: Int256.t,
  gasLimit: Int256.t,
  gasUsed: Int256.t,
  timestamp: Int256.t,
  extraData: Bytes.t, // Bytes.length < 32
  mixHash: Hash.t
  nonce: Int64.t
};


let difficulty = header => {
  let genesisDifficulty = Z.pow2(17); // 131072 
  switch (header.number) {
  | 0 => genesisDifficulty
  | _ => Z.max(genesisDifficulty, 0 /* complicated math goes here */)
  };
};

/**
  Validates the block header, returns true if valid, otherwise false.
 */
let valid = t => true;
*/

