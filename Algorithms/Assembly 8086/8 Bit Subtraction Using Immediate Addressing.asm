data segment
    res db ?
data ends

code segment
    assume cs:code, ds: data

    start:
    mov ax, data
    mov ds, ax
    mov al, 09h
    mov bl, 04h
    sub al, bl
    mov res, al

code ends
end start
