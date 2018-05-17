let rec to_binary = length =>
  if (length == 0) ""
  else to_binary(length / 256) ++ String.make(1, Char.chr(length mod 256));

let encode_length = (length, offset) =>
  if (length < 56) {
    Char.chr(length + offset)
    |> String.make(1);
  } else if (length < int_of_float(258. ** 8.)) {
    let binary_length = to_binary(length);
    let len_prefix = String.length(binary_length) + offset + 55;
    String.make(1, Char.chr(len_prefix)) ++ binary_length;
  } else {
    raise(Invalid_argument("Provided input was too long."));
  };

let is_single_char = str => String.length(str) == 1 && Char.code(str.[0]) <= 128;

let encode_string = str =>
  if (is_single_char(str)) {
    str
  } else {
    encode_length(String.length(str), 128)
  };

