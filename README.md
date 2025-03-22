# RISC-V Assembler (PHASE-I)

The project contains a program that assembles a **RISC-V code to machine code**. It is a part of the CS204 - Computer Architecture course being taught under Prof. T.V. Kalyan at IIT Ropar. The language used in the program is **C++ version 20**

## Authors

- Atul Kharat (2023CSB1105)
- Nachiket Patil (2023CSB1136)

## Table of Contents

- [About](#about)
- [Features](#features)
- [Usage](#usage)

## About

This project implements a basic RISC-V assembler in C++. It consists of a two-pass process: the first pass processes the `.data` section, storing variables and data in memory, while the second pass processes the `.text` section, generating machine code instructions.

## Features
The assembler supports the following commands:
### R Format
- add
- and
- or
- sll
- slt
- sra
- srl
- sub
- xor
- mul
- div
- rem

### I Format
- addi
- andi
- ori
- lb
- ld
- lh
- lw
- jalr

### S Format
- sb
- sw
- sd
- sh

### SB Format
- beq
- bne
- bge
- blt

### U Format
- auipc
- lui

### UJ Format
- jal

 and the following assembler directives:
- .text
- .data
- .byte
- .half
- .word
- .dword
- .asciz

## Usage
1. Ensure all the files are in the same folder and compile main.cpp.

   ```bash
   g++ main.cpp

2. Execute the executable file and ensure there is a file "input.asm" to provide input. A sample code has been provided in the "input.asm" in this repository.

   For Windows:
   ```bash
   ./a.exe
   ```
   For Linux:
   ```bash
   ./a.out
   ```
3. The code must be basic RISC-V code.
4. Full-line comments are allowed, but inline comments are not supported.
5. Immediate values must only be given in Decimal format and no other format like hexadecimal.
The output will be generated in a file "output.mc" which will contain the machine code of instructions along with the program counter and the data segment of the code
   

