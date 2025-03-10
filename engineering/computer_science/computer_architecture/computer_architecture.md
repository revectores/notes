# Comptuer Architecture



##### # Five-Stage Pipeline Processor

1. **Instruction Fetch**. **Program Counter** (PC) is a register that stores address of next instruction. **Fetch Unit** loads insturction to ==todo: ?==, then PC++.
2. **Instruction Decode**. Decoder analyse the operand and address-access method, preparing data that execution stage requires.
3. **Execute**. 
4. **Memory Access**. Load & Store. 
5. **Write Back**.



==todo: make a diagram for this==

Instruction Fetch -> Instruction decode -> execute -> memory acces -> write back



##### # Instruction Pipelining and Optimization

- Devide stage. Improve parallel level and clock frequency.
- Stall to avoid **hazard**.
  - **Structural hazard**. Solution: **Hypersaclar**. Add more processor unit for that specfic task.
  - **Data hazard**. Data Dependency, a instruction depends on the result of another instruction. There are different type of data dependency: true dep and false dep. False dep can be fully **eliminated** by **register renaming**, while true dep can be somehow relieve by **bypassing** and **out-of-order execution**.
    - true dep: read after write.
    - false dep: (1) write after read anti-dependence. (2) write after write output dependence.
    - bypassing: pass data directly from previous instruction to next instruction, without re-write to register.
    - out-of-order execution.
  - **Control hazard**. prediction execution.



##### # Benchmarking Pipelining

CPI: Cycles Per Instruction.

IPC: Instruction Per Cycle.



##### # CISC & RISC

now they are converging