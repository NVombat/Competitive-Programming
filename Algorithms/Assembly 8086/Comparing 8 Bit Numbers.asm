DATA SEGMENT
    NUM1 DB 50
    NUM2 DB 45
DATA ENDS

CODE SEGMENT

    ASSUME CS: CODE, DS: DATA
    START: MOV AX, DATA

    MOV DS, AX
    MOV AL, NUM1
    MOV BL, NUM2
    CMP AL, BL
    JLE TAG
    TAG: MOV DL, AL
         MOV AH, 02H
         MOV DL, 'T'
         INT 21H
    MOV AX, 4CH
    INT 21H
    CODE ENDS
    END START
