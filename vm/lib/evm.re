/**
  State is a tuple of available gas, program counter,
  the contents of the memory, number of words in memory,
  and the stack contents
 */
open Core_kernel;

type state = (Int256.t, Int256.t, array(Int256.t), Int256.t, Stack.t);

type context = {name: string};
