DATA SEGMENT
    N1 DB 00000000B
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

    START:
    MOV AX, DATA
    MOV DS, AX

    MOV AH, 0000H
    MOV AL, N1

    NOT AL

    CODE ENDS

END START
