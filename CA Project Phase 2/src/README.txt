======================================================
Functional Simulator for 32bit RISCV ISA instructions
======================================================

README

Table of contents
1. Directory Structure
2. Getting Started: Installation and Running 
3. Output Format
4. Contributers



Directory Structure:
--------------------
CS204-Project
  |
  |- src
      |- main.cpp
      |- Makefile
      |- myARMSim.cpp
      |- D_Memory.mc
      |- data_out.mc
      |- gui.py
      |- inp.py
      |- input.mc
      |- output_log.mc
      |- README.txt
      |- register.mc
      |- test_case.mc
      |- factorial.mc
      |- bubblesort.mc
      |- fibonacci.mc
  |- Project-statement.txt
  |- README.md


Getting Started: Installation and running
-------------------------------------------
  Prerequisites
  - pip (>21.0.3)
  - python (>3.7)

  Libraries Used
    Back-end - Python3 and G++
      - os:  for getting and adding path to certain file locations.
      - sys:  for reading and editing files with ease.
    Front-end - Python3
      - PyQT5:  for the Graphic User Interface.
      - qdarkstyle:  for dark theme
  
    Running the GUI version
    --------------------------
      - Your computer should have Python3, G++ and Makefile installed.You can check if they are installed or not by using the following commands
            
            python3 --version
            g++ --version 
            make --version
      - Download the zip file of the repository
      - cd into the Computer Architecture then to CA Project Phase 2 then to src
      - Now run the following command in terminal
            make 
      - The above commands will open the GUI. You have to press ASSEMBLE, which will compile and run the cpp files.
      - Wait for the message "Ready to run" and then press the RUN button.
      - This will print the output log, update the register values and data memory in the GUI.
    
    Running the Basic version without GUI
    ---------------------------------------
      - Type the following command after cd into the src folder
            g++ main.cpp myRISCVSim.cpp -I ../include
      - This will run the program and output the output log in output_log.mc, data memory in D_memory.mc and register values in register.mc

    Feeding Input to the program
    -------------------------------
       - The src Folder contains a test_case.mc file in which the machine code you want to run will go in the following format (containing the instruction code as well as the pc).The exit code will be 0x00000073 which basically is RISCV encoding of ecall instruction,
            0x0 0x00500513
            0x4 0x008000EF
            0x8 0x0440006F
       - The machine code in this format for the 3 test cases i.e. bubblesort (bubblesort.mc), sum of factorial (factorial.mc) and fibonacci (fibonacci.mc) are provided in the root directory. You can copy-paste the code from there to test_case.mc file in src folder for running them. 
       - If you want to run any code written in assembly, Go to venus simulator (online), copy-paste the dump in the input.py file in src folder, then run the inp.py file. It will convert the dump into the required assembly format and write it in the test_case.mc file. You can run the code to see the output.

Output Format
-----------------
   Check the generated folder for details of compilation. It contains:
       output_log.mc : contains general stats about the different stages like fetch, decode, ALU, memory access, register writeback and details of changes in temporary registers for each cycle
       data_out.mc: details of instruction memory
       register.mc: details of registers
       D_Memory.mc: details of data memory


Contributers
----------------
  - Atul Kharat          2023CSB1105
  - Nachiket Patil       2023CSB1136
