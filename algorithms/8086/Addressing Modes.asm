data segment
    data1 db 23h
    data2 dw 1234h
    data3 db 0h
    data4 dw 0h
    data5 dw 2345h,6789h
data ends

code segment
    assume cs:code,ds:data

    start:
    mov ax,data
    mov ds,ax

    mov al, 25h         ;immediate addressing mode
    mov ax, 2345h

    mov bx,ax           ;direct addressing mode
    mov cl,al

    mov al,data1
    mov ax,data2
    mov data3,al
    mov data4,ax

    mov bx,offset data5 ;indirect register addressing
    mov ax,[bx]

    mov di, 02h         ;destination index register - stores some index
    mov ax,[bx+di]      ;indexed addressing

    mov ax,[bx+0002h]   ;relative addressing
    mov al,[di+2]

    mov ah,4ch          ;4C hex

    int 21h

code ends
end start
