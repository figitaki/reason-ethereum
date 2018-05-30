# ![Reason Ethereum](logo.png)
Ethereum light client written in ReasonML.

How to build the project
--

Run `make` to compile the libraries and executables that are
meant to be installed.
```sh
$ make
```

How to run tests
--

```sh
$ make test
```

How to use local libraries interactively
--

Use `jbuilder utop DIR` where DIR if the folder contains the `jbuild`
file for a library. For instance, our `sub2` sample library can be
used as follows:

```ocaml
$ jbuilder utop rlp/lib
...
utop # open Rethereum_rlp;;
utop # Rlp.encode (Rlp.empty ());;
- : unit = ()
```

Installation
--

The project can be installed with or without opam.
Without opam, you can run the following which relies directly on
dune/jbuilder:
```sh
$ make install
```
Similarly:
```sh
$ make uninstall
```

With opam, you can install the current development version of your
project as a single opam package. It will override the currently
installed package of the same name, if any:
```sh
$ opam pin add proj .
```
For more information on `opam pin`, please consult the opam documentation.

The advantage of the opam-based method is that other opam packages can
depend on this one, and opam will recompile them automatically as
necessary.
