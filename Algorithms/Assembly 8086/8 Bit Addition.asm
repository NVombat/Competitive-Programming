data segment
    a db 5h ;db is define byte and initializes memory with one or more byte values
    b db 7h ;'h' in this case symbolises hexadecimal
    res db ?
    data ends

code segment
    assume cs:code, ds: data
    ;assume directive tells compiler that CS(Code segment) contains CODE and DS(Data segment) contains DATA
    ;The ASSUME directive tells the assembler what segment register you are going to use to access a segment.

    start: ;Starts Program
    mov ax, data ;ax - Accumulator register used for arithmetic and logical operations ;ax gets address of data
    mov ds, ax   ;Gets address of data segment   ;data segment register stores that address
    mov al, a    ;Accumulator register is 16bit - 8bit Al and 8bit Ah;
    mov bl, b    ;Base register is 16 bit - so 8 bit
    add al, bl   ;Adds values in AL and BL to get sum
    mov res, al   ;CX general purpose register stores value of AX
    ;int 3 ;Uses an interrupt to exit the program

    code ends
end start
