type context;

/* Private key represented as a 32-byte string */
type seckey = string;

/* Public key represented as a 64-byte string */
type pubkey;

/* Recoverable ECDSA signature as a tuple of (r, s, v) */
type signature = (int, string, string);

let create_context: unit => context;

let random_seckey: unit => seckey;

let create_pubkey: (context, seckey) => pubkey;

let serialize_pubkey: (context, pubkey) => string;

/** Creaet an ECDSA Signature
 *
 * Returns a signature of the provided message.
 * Params - msg: the 32-byte message hash being signed.
 *          key: a 32-byte secret key
 */
let sign: (~msg: string, ~key: seckey) => signature;

/*let recover_pubkey: (~msg: string, ~signature: signature) => pubkey; */

/** Verify an ECDSA signature.
 *
 * Returns: true: correct signature
 *          false: incorrect or unparseable signature
 */;
/* let verify: (Signature.t, ~msg: string, ~pubkey: Pubkey.t) => string; */
