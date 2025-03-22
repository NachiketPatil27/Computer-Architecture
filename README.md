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

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <br />
<h1  style="color:blue;text-align:center" ><strong>CS204 Project(PHASE-II) - Functional Simulator</strong></h1>

<p>The aim of this project is to simulate the machine level execution of RISC-V as well as the execution of RISC-V 32-bit instructions using a high level 
language. The Project also aims to give final updates to the user regarding each step of the execution of the program. It also returns the final status of 
the memory and registers as output for the user to analyse the working of their programs thoroughly. The Project currently allows the user to use 26 
different instructions and can be extended to allow the use of any number of instructions as long as the instructions are supported by 32-bit RISC-V ISA. The 
program executes each instruction using five stages as described in the RISC-V architecture. The instruction memory size is upto 1000 instructions.</p>

<br/>
<h2>Table of Contents</h2>
<ul>
  <li><a href="#getting-started">Getting Started: Installation and Running</a></li>
  <li><a href="#contributors">Contributors</a></li>
</ul>
<br>
<h2 id="getting-started">Getting Started: Installation and running</h2>

### Prerequisites
- `pip` (>21.0.3)
- `python` (>3.7)

### Libraries Used

#### Back-end - Python3 and G++
- `os: ` for getting and adding path to certain file locations.
- `sys: ` for reading and editing files with ease.
#### Front-end - Python3
- `PyQT5: ` for the Graphic User Interface.
- `qdarkstyle: ` for dark theme

<br>
<h3>Running the GUI version</h3>
<ul>
  <li>Your computer should have Python3, G++ and Makefile installed.You can check if they are installed or not by using the following commands</li>
  <pre><code>
    python3 --version
    g++ --version 
    make --version
 </code></pre>
  <li>Download the zip file of the repository</li>
  <li>cd into the Computer-Architecture then to CA Project Phase 2 and to src</li>
  <li>Run the inp.py file to make the test_case</li>
  <li>To run the GUI version of the project execute the gui.py file</li>
<ul> 
  <li>Once you open the GUI. You have to press ASSEMBLE, which will compile and run the cpp files. </li>
  <li>Wait for the message "Ready to run" and then press the RUN button. </li>

  <li>This will print the output log, update the register values and data memory in the GUI.</li>
</ul>
<h3>Running the Basic version without GUI</h3>
<ul>
  <li>Type the following command after cd into the src folder</li>
  <pre><code>
    g++ main.cpp myRISCVSim.cpp -I ../include
  </code></pre>
  <li>This will run the program and output the output log in output_log.mem, data memory in D_memory.mem and register values in register.mem</li>
</ul>
<h3>Feeding Input to the program</h3>
<ul>
  <li>The src Folder contains a test_case.mem file in which the machine code you want to run will go in the following format (containing the instruction code as well as the pc).The exit code will be 0x00000073 </li>
  <pre><code>
    0x0 0x00500513
    0x4 0x008000EF
    0x8 0x0440006F
  </code></pre>
  <li>The machine code in this format for the 3 test cases i.e. bubblesort (bubblesort.mc), factorial (factorial.mc) and fibonacci (fibonacci.mc) are provided in the root directory. You can copy-paste the code from there to test_case.mc file in src folder for running them.</li>
  <li>If you want to run any code written in assembly, Go to venus simulator (online), copy-paste the dump in the input.py file in src folder, then run the inp.py file. It will convert the dump into the required assembly format and write it in the test_case.mc file. You can run the code to see the output.</li>
</ul>
<br>

<h3>Output Format</h3>

Check the generated folder for details of compilation. It contains:

- `output_log.mc :` contains general stats about the different stages like fetch,decode,ALU,memory access,register writeback and details of changes in temporary registers for each cycle
- `data_out.mc:` details of instruction memory
- `register.mc:` details of registers
- `D_Memory.mc:` details of data memory


<h2 id="contributors">Contributors</h2>

<div align="center">
  <strong>
    <a href="https://github.com/AtulKharat256">Atul Kharat </a> &emsp;
    <a href="https://github.com/NachiketPatil27">Nachiket Patil</a> &emsp;
  </strong>
</div>

</body>
</html>


