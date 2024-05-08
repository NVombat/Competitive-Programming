DATA SEGMENT
    A DB 09H
    B DB 02H
    RES DW ?
    DATA ENDS

CODE SEGMENT

    ASSUME CS: CODE, DS: DATA
    START:
    MOV AX, DATA
    MOV DS, AX
    MOV AX, 0000H
    MOV BX, 0000H
    MOV AL, A
    MOV BL, B
    MUL B
    MOV RES, AX
    INT 3
    CODE ENDS

END START
