open Core_kernel;

type buffer = Bigstring.t;

type context = buffer;

external create_context : unit => context = "context_create";

type seckey = string;

external generate_seckey : buffer => seckey = "generate_seckey";

let random_seckey = () => {
  let buf = Bigstring.create(32);
  let _ = generate_seckey(buf);
  buf |> Bigstring.to_string;
};

type pubkey = string;

external ec_pubkey_create : (context, buffer, buffer) => int =
  "ec_pubkey_create";
external ec_pubkey_serialize : (context, buffer, buffer) => int =
  "ec_pubkey_serialize";

let create_pubkey = (ctx, sk) => {
  let buf = Bigstring.create(64);
  let _ = ec_pubkey_create(ctx, buf, Bigstring.of_string(sk));
  buf |> Bigstring.to_string;
};

let serialize_pubkey = (ctx, pk) => {
  let buf = Bigstring.create(65);
  let _ = ec_pubkey_serialize(ctx, buf, Bigstring.of_string(pk));
  let str = Bigstring.to_string(buf);
  String.sub(str, ~pos=1, ~len=64);
};

type signature = string;

external ec_sign_recoverable : (context, buffer, buffer, buffer) => int =
  "ec_sign_recoverable";

let sign = (~msg, ~secret) => {
  let ctx = create_context();
  let buf = Bigstring.create(65);
  let _ =
    ec_sign_recoverable(
      ctx,
      buf,
      Bigstring.of_string(secret),
      Bigstring.of_string(msg),
    );
  buf |> Bigstring.to_string;
};
