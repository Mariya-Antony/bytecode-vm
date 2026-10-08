# bytecode-vm

A stack-based bytecode virtual machine and two-pass assembler, written in C.

You write a small program in assembly-like text, the assembler turns it into bytecode, and the VM runs it.

## Status

Work in progress.

- [x] Project setup
- [ ] Instruction set design (see DESIGN.md)
- [ ] VM core
- [ ] Assembler
- [ ] Example programs (factorial, Fibonacci, recursion)
- [ ] Disassembler and trace mode
- [ ] Tests and sanitizer checks
- [ ] Benchmark

## Example

This program counts down from 3:

```
PUSH 3
STORE 0
loop:
  LOAD 0
  JZ end
  LOAD 0
  PRINT
  LOAD 0
  PUSH 1
  SUB
  STORE 0
  JMP loop
end:
  HALT
```

Expected output:

```
3
2
1
```

## How it works

The machine keeps a stack of numbers. Instructions push numbers onto it or pop numbers off it. For example, `PUSH 2`, `PUSH 3`, `ADD` leaves `5` on the stack.

Main parts:

- **Value stack**: holds numbers while calculating
- **Call stack**: remembers where to return after `CALL`
- **Memory slots**: numbered boxes that act as variables
- **Instruction pointer**: tracks which instruction runs next

## Instruction set

| Instruction | Description |
|---|---|
| `PUSH n` | Put n on top of the stack |
| `POP` | Remove the top value |
| `ADD`, `SUB`, `MUL`, `DIV`, `MOD` | Arithmetic on the top two values |
| `JMP addr` | Jump to addr |
| `JZ addr` | Pop a value; jump to addr if it is 0 |
| `CALL addr` | Save return address, jump to addr |
| `RET` | Return to the saved address |
| `STORE n` | Pop a value into memory slot n |
| `LOAD n` | Push the value in slot n |
| `PRINT` | Pop a value and print it |
| `HALT` | Stop the machine |

## Build and run

TODO: fill in once the Makefile works, e.g.

```
make
./vm examples/countdown.asm
```

## Testing

TODO: describe `make test` and the sanitizer build once they exist.

## Limitations and next steps

- Only 64-bit integers (no strings or other types)
- Fixed-size stacks
- Possible future work: faster instruction dispatch, a small language that compiles to this bytecode, local variables and stack frames