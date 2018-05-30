/*
    Run all the OCaml test suites defined in the project.
 */
let test_suites: list(Alcotest.test(unit)) = [
  ("Core", Test_core.A.tests),
  ("Rlp.Rlp", Test_rlp.B.tests)
];

let () = Alcotest.run("rethereum", test_suites);
