data segment
    N1 dw 4004h ;dw is define word and initializes memory with one or more word values
    N2 dw 1001h ;'h' in this case symbolises hexadecimal
    res dw ?
    data ends

code segment
    assume cs:code, ds: data
    ;assume directive tells compiler that CS(Code segment) contains CODE and DS(Data segment) contains DATA 
    ;The ASSUME directive tells the assembler what segment register you are going to use to access a segment. 

    start: ;Starts Program
    mov ax, data ;ax - Accumulator register used for arithmetic and logical operations ;ax gets address of data
    mov ds, ax   ;Gets address of data segment   ;data segment register stores that address
    mov ax, N1   ;Accumulator register is 16bit stores N1
    mov bx, N2   ;Base register is 16 bit Stores N2
    add ax, bx   ;Adds values in Ax and Bx to get sum
    mov res, ax   ;CX general purpose register stores value of AX
    int 21h ;Uses an interrupt to exit the program

    code ends
end start
