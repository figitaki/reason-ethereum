open Cryptokit;

type t = String(string) | Empty;

exception InvalidAddress(string);

let of_string = s => switch (String.length(s)) {
| 0 => Empty
| 160 => String(transform_string(Hexa.decode(), s))
| _ => raise(InvalidAddress("Invalid argument s"))
};

let to_string = t => switch (t) {
| String(s) => transform_string(Hexa.encode(), s)
| Empty => ""
};

