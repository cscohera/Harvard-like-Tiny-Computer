# Harvard-like-Tiny-Computer

Program that simulates a variant of the Tiny Harvard
Architecture. In this implementation memory (RAM) is split into Instruction Memory (IM) and Data
Memory (DM). Code implements the basic instruction set architecture (ISA) of the Tiny

Machine Architecture:
1   LOAD
2   ADD
3   STORE
4   SUB
5   IN
6   OUT
7   END
8   JMP
9   SKIPZ



#Tiny Virtual Machine

HOW TO COMPILE/EXECUTE:
create a txt file
txt file must be in number pairs of two ie. 3 7 on each line and be a txt file.
                                            4 6
Use commands 
gcc -o CarsonScoherasvm CarsonScoherasvm.c
./CarsonScoherasvm Elf.txt

How to input the multiplication:

input1 = 0 (to accumulate the result here)

input2 = 1 (top decrement variable that control the loop).

input3: first number to be multiplied (for example, 5)

input4: second number to be multiplied (for example, 3)

HOW IT WORKS:

This program simulates in C language the Tiny Harvard Architecture. In doing so the task was to include the basic
instruction set for the architecture. This being LOAD,ADD,STORE,SUB,IN,OUT,END,JMP,SKIPZ. It does this by
first reading in from a file the opcode (specifies which operation is to be performed) and the address (determines the right register that can be used for the operation). Then putting this data into the Instruction memory array with values alternating as opcode IM[0] address IM[1] then next opcode IM[2] etc... we can use the fetch execute cycle inorder to properly implement this tiny machine and use our set of instructions. To do this properly I needed to use a few more parts ie: PC,MAR1,MDR1,MAR2,MDR2,IR,DM,and A. Then using a switch statement based on opcode instruction we can propely run each basic function based on the information provided in the assignment
