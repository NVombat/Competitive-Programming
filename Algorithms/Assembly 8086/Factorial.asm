DATA SEGMENT
    A DW 5H
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

    START:
    MOV AX, DATA
    MOV DS, AX

    MOV CX, A
    MOV AX, 0001H
    L1: MUL CX
    LOOP L1

    CODE ENDS

END START
