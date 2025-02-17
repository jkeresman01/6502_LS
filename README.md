## Langauge server for 6502 assembly ---> Not baked yet

Toy langaguge server for 6502 assembly, providing completion items and information about instruction set on hover.

## 6502 processor ##

TODO: short desc

Registers:

* PC	program counter	(16 bit)
* AC	accumulator	(8 bit)
* X	  register	(8 bit)
* Y	  register	(8 bit)
* SR	status register [NV-BDIZC]	(8 bit)
* SP	stack pointer	(8 bit)



## Covered instruction  ##


| Mnemonic | Description |
|----------|------------|
| **ADC**  | Add with carry |
| **AND**  | And (with accumulator) |
| **ASL**  | Arithmetic shift left |
| **BCC**  | Branch on carry clear |
| **BCS**  | Branch on carry set |
| **BEQ**  | Branch on equal (zero set) |
| **BIT**  | Bit test |
| **BMI**  | Branch on minus (negative set) |
| **BNE**  | Branch on not equal (zero clear) |
| **BPL**  | Branch on plus (negative clear) |
| **BRK**  | Break / interrupt |
| **BVC**  | Branch on overflow clear |
| **BVS**  | Branch on overflow set |
| **CLC**  | Clear carry |
| **CLD**  | Clear decimal |
| **CLI**  | Clear interrupt disable |
| **CLV**  | Clear overflow |
| **CMP**  | Compare (with accumulator) |
| **CPX**  | Compare with X |
| **CPY**  | Compare with Y |
| **DEC**  | Decrement |
| **DEX**  | Decrement X |
| **DEY**  | Decrement Y |
| **EOR**  | Exclusive OR (with accumulator) |
| **INC**  | Increment |
| **INX**  | Increment X |
| **INY**  | Increment Y |
| **JMP**  | Jump                          |
| **JSR**  | Jump subroutine               |
| **LDA**  | Load accumulator              |
| **LDX**  | Load X                        |
| **LDY**  | Load Y                        |
| **LSR**  | Logical shift right           |
| **NOP**  | No operation                  |
| **ORA**  | OR with accumulator           |
| **PHA**  | Push accumulator              |
| **PHP**  | Push processor status (SR)    |
| **PLA**  | Pull accumulator              |
| **PLP**  | Pull processor status (SR)    |
| **ROL**  | Rotate left                   |
| **ROR**  | Rotate right                  |
| **RTI**  | Return from interrupt         |
| **RTS**  | Return from subroutine        |
| **SBC**  | Subtract with carry           |
| **SEC**  | Set carry                     |
| **SED**  | Set decimal                   |
| **SEI**  | Set interrupt disable         |
| **STA**  | Store accumulator             |
| **STX**  | Store X                       |
| **STY**  | Store Y                       |
| **TAX**  | Transfer accumulator to X     |
| **TAY**  | Transfer accumulator to Y     |
| **TSX**  | Transfer stack pointer to X   |
| **TXA**  | Transfer X to accumulator     |
| **TXS**  | Transfer X to stack pointer   |
| **TYA**  | Transfer Y to accumulator     |

### Completions [intelisense]  ###

[![asciicast](https://asciinema.org/a/Vpxr4wl0QqZ83fRqBJO7xGunM.svg)](https://asciinema.org/a/Vpxr4wl0QqZ83fRqBJO7xGunM)

### Hover ###
[![asciicast](https://asciinema.org/a/syKCKR74Qze1xiQ46AxoEDiyv.svg)](https://asciinema.org/a/syKCKR74Qze1xiQ46AxoEDiyv)

