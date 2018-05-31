
# [![Reason Ethereum](media/header.png)](https://rethereum.com)
> Experimental light client

[![GitHub release](https://img.shields.io/github/release/figitaki/reason-ethereum.svg)](https://github.com/figitaki/reason-ethereum/releases) [![Build status](https://img.shields.io/travis/figitaki/reason-ethereum/master.svg)](https://travis-ci.com/figitaki/reason-ethereum/master.svg)
![Coveralls github branch](https://img.shields.io/coveralls/github/figitaki/reason-ethereum/master.svg)

As the Ethereum blockchain has evolved, the need for an optimized mobile implementation has increased. Rethereum tackles this challenge by implementing the light client protocol. Switiching from Geth to Rethereum brought the sync time from 4 hrs to just 20 min.

Installation
--

First, to obtain the binaries, we use npm so you need Node to be installed.

```bash
$ npm i -g rethereum
```

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
