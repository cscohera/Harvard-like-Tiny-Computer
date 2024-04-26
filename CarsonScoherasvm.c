/* 
   Carson Scohera
   CGS3269 HW4
   4/10/24
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Instruction Set that should stay constant
#define LOAD 1
#define ADD 2
#define STORE 3
#define SUB 4
#define IN 5
#define OUT 6
#define END 7
#define JMP 8
#define SKIPZ 9

//global ints that have a constant size
int IM[250];
int DM[10] = {0};


int main(int argc, char **argv) {

    //error if improper file format
    if (argc != 2){
        printf("Error Could not open file");
    }

    //opens file if it exists and fits file line requirements
    FILE* elf = fopen(argv[1], "r");
    if (elf == NULL){
        printf("Error no such file");
        return 0;
    }

    //needed to get the opcode and the address when we scan in the file and use x to move through IM array 
    //in order to get each opcode and adress to its own spot in the array
    int opcode;
    int address;
    int x = 0;

    //reads line by line until we read line without two arguments
    //using x and i so opcode goes then address goes in next element of the array as directed in directions
    while (fscanf(elf, "%d %d", &opcode, &address) == 2){
        IM[x] = opcode;
        IM[x+1] = address;
        x+=2; 
    }

       //close file now because we no longer need it
        fclose(elf);


    //if scanning in file was successful these should print
    printf("Reading Program...\n");
    printf("Program Loaded.\n");
    printf("Run.\n");

    
    //parts of the tiny computer architecture that need declaring not constant because they will change
    int PC = 0;
    int A = 0;
    int MAR1, MDR1[2], MAR2, MDR2, IR[2];
    int input;
    
    
    //while we don't reach the end of the set of instructions
    while(1){
        //prints out whats the data in the current cycle of instructions 
        printf("PC = %d | A = %d | DM = [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n\n",PC, A, DM[0], DM[1], DM[2], DM[3], DM[4], DM[5], DM[6], DM[7], DM[8], DM[9]);

        //Fetch cycle opcode is IR[0] address is IR[1] as with mdr1[0] and mdr1[1]
        MAR1 = PC;
        MDR1[0] = IM[MAR1];
        MDR1[1] = IM[MAR1+1];
        IR[0] = MDR1[0];
        IR[1] = MDR1[1];


        //increments program counter to next set of instructions 
        PC +=2;

    //execute based on the opcode instruction we fetch does one instruction each time
    switch (IR[0]) {
        case LOAD:
            //copy data needed then setting it to accumulator so we can interact with it
            MAR2 = IR[1];
            MDR2 = DM[MAR2];
            A = MDR2;
            printf("/* Loading value at memory location %d */\n", MDR2);
            break;
        case ADD:
            //copy data needed then Adding to the vaule in the accumulator
            MAR2 = IR[1];
            MDR2 = DM[MAR2];
            A = A + MDR2;
            printf("/* Adding value at memory location %d to accumulator */\n", MDR2);
            break;
        case STORE:
            //copy content into fields and store in Data memeory
            MAR2 = IR[1];
            MDR2 = A;
            DM[MAR2] = MDR2;
            printf("/* Storing accumulator to memory location %d */\n", DM[MAR2]);
            break;
        case SUB:
            //copy data needed and subtract by current value in accumulator
            MAR2 = IR[1];
            MDR2 = DM[MAR2];
            A = A - MDR2;
            printf("/* Subtracting value at memory location %d from accumulator */\n", MDR2);
            break;
        case IN:
            //ask for user input and scan into accumulator for interaction
            printf("Input data: \n");
            scanf("%d", &A);
            break;
        case OUT:
            //output result
            printf("/* Outputting accumulator to screen */\n");
            printf("The result is: %d\n\n", A);
            break;
        case END:
            //end program
            printf("Program complete\n\n");
            return 0;
        case JMP:
            //jump to a instruction
            PC = IR[1];
            printf("/* Jumping to address %d */\n", PC);
            break;
        case SKIPZ:
            //skips over an instruction
            printf("/* SKIPZ: Checking if accumulator is 0 */\n");
            if (A == 0){
                PC+= 2;
                printf("True: skipping next instruction\n");
            }
            else
                printf("False: Running next instruction\n");
            break;
        }
        
    }

    //end of program
    return 0;
} 


