data segment
    res db ?
    data ends

code segment
    assume cs:code, ds: data

    start:
    mov ax, data
    mov ds, ax
    mov al, 03h
    mov bl, 05h
    add al, bl
    mov res, al

    code ends
end start
