open Base;
open Stdio;
module C = Configurator;

let write_sexp = (fn, sexp) =>
  Out_channel.write_all(fn, ~data=Sexp.to_string(sexp));

let () =
  C.main(~name="secp256k1", c => {
    let default: C.Pkg_config.package_conf = {
      libs: ["-lsecp256k1"],
      cflags: [],
    };

    let conf =
      switch (C.Pkg_config.get(c)) {
      | None => default
      | Some(pc) =>
        Option.value(
          C.Pkg_config.query(pc, ~package="libsecp256k1"),
          ~default,
        )
      };
    write_sexp("c_flags.sexp", sexp_of_list(sexp_of_string, conf.cflags));
    write_sexp(
      "c_library_flags.sexp",
      sexp_of_list(sexp_of_string, conf.libs),
    );
  });
