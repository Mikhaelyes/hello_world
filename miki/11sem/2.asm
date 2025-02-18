%include "st_io.inc"
global _start
section .data
t1 dw 0011101010010100b	; 7:5:20
t2 dw 0010101010000110b	; 6:4:21
y1 dw 0000000001111111b
m1 dw 0000011110000000b
d1 dw 1111100000000000b
d2 dw 0000000000011111b
m2 dw 0000000111100000b
y2 dw 1111111000000000b
section .text
_start:
xor ebx, ebx
mov bx, [t2]
and [d2], bx
and [m2], bx
shr word [m2], 5
and [y2], bx
shr word [y2], 9
xor eax, eax
mov ax, [d2]
SIGNINT eax
PUTCHAR ':'
mov ax, [m2]
SIGNINT eax
PUTCHAR ':'
mov ax, [y2]
SIGNINT eax
PUTCHAR 0xa

xor ebx, ebx
mov bx, [t1]
and [y1], bx
and [m1], bx
shr word [m1], 7
and [d1], bx
shr word [d1], 11
xor eax, eax
mov ax, [y1]
SIGNINT eax
PUTCHAR ':'
mov ax, [m1]
SIGNINT eax
PUTCHAR ':'
mov ax, [d1]
SIGNINT eax
PUTCHAR 0xa

xor bx, bx
mov bx, [t2]
xor [t2], bx
shl word [y1], 9
shl word [m1], 5
mov ax, [d1]
or [t2], ax
mov ax, [m1]
or [t2], ax
mov ax, [y1]
or [t2], ax
FINISH


