# randomx-fu

**Proof-of-Concept mutation tweak for RandomX** to disrupt miner centralization and make it harder for fixed-hardware setups to dominate.

## What It Does

Adds a simple opcode mutation (XOR 0x5A) to the RandomX VM's instruction table. This forces any optimized ASIC/FPGAs or centralized miners to recompile and reoptimize on every fork or chain variant that uses this tweak.

## How to Use

1. Integrate `randomx_vm.cpp` into your RandomX-based chain or fork.
2. Add a call to `randomx_fu::maybe_mutate_opcode_table()` during VM setup.
3. Pass the `--randomx-fu` flag to enable the opcode mutation.

## Why

Monero and other RandomX chains face potential miner centralization. This PoC is designed to demonstrate a defensive fork-level tweak that can make coordinated attacks or fixed-hardware setups much harder to sustain.

## Warning

This is just a sketch. You must patch and test it in a real-world RandomX VM environment.
