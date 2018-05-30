type t = {
  header: Header.t,
  transactions: list(Transaction.t),
  omers: list(Header.t)
};
