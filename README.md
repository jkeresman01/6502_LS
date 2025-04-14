<div align="center">

  <h1>6502 assembly language server</h1>
  <h3> !!!!!!!   Not baked yet   !!!!!!! </h3>
  <h6> ---> Langauge server for 6502 assembly <--- </h6>

![C++](https://img.shields.io/badge/C++-blue?style=for-the-badge&logo=c%2B%2B)
![Work In Progress](https://img.shields.io/badge/Work%20In%20Progress-orange?style=for-the-badge)

</div>

## Table of Contents ##

- [6502 Langauge server](#)
   - [Completions](#)
   - [Hover](#)
   - [Diagnostics](#)
   - [CodeActions](#)
- [6502 processor](#)
  - [Overivew](#)
  - [Instruction Set](#)
- [Clients](#)
  - [Neovim](#)
  - [Emacs](#)
  - [VSCode](#)
- [Build](#)

## 6502 lanage server ##

This is fairly simple implementation of language server protocol for 6502 assembly.

A language server is a tool that provides language-specific features like auto-completion, go-to-definition, and find-all-references to an editor or integrated development environment (IDE) through the Language Server Protocol (LSP).

For more information visit official microsofts documentation.

### Completions  ###

[![asciicast](https://asciinema.org/a/Vpxr4wl0QqZ83fRqBJO7xGunM.svg)](https://asciinema.org/a/Vpxr4wl0QqZ83fRqBJO7xGunM)

### Hover ###

[![asciicast](https://asciinema.org/a/syKCKR74Qze1xiQ46AxoEDiyv.svg)](https://asciinema.org/a/syKCKR74Qze1xiQ46AxoEDiyv)

### Diagnostics  ###

/// TODO

### Code actions  ###

/// TODO

## 6502 processor ##

///  TODO: short desc

## Overview ##

/// TODO: short desc

Registers:

* PC	program counter	(16 bit)
* AC	accumulator	(8 bit)
* X	  register	(8 bit)
* Y	  register	(8 bit)
* SR	status register [NV-BDIZC]	(8 bit)
* SP	stack pointer	(8 bit)


## Instruction set  ##

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


## Clients ##

Instructions on how to setup clients are provided for following editors: Neovim, Emacs, VSCode(don't use this one).

### Neovim ###

Neovim supports the Language Server Protocol (LSP), which means it acts as a client to LSP servers and includes a Lua framework `vim.lsp`.

To configure the LSP client, you can use this example:

```Lua
vim.api.nvim_create_autocmd("FileType", {
    pattern = "txt",

    callback = function()

        local client = vim.lsp.start({
            name = "6502LS",
            cmd = {"/path/to/6502LS/binary"}
        })

        if not client then
            vim.notify "No can do for 6502 ASM language server!"
        else
            vim.lsp.buf_attach_client(0, client)
        end
    end

})
```

### Emacs ###

/// TODO

### VSCode ###

/// TODO

## Build ##

``` shell
cd 6502_LS
mkdir build && cd build
cmake ..
make -j$(nproc)
```

