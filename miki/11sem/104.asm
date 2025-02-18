%include "st_io.inc"
global _start
section .data
a db 11111111b
x1 db 11100000b
x2 db 00011000b
x3 db 00000111b
section .text
_start:
xor eax, eax
mov al, [a]
and [x3], al
and [x2], al
shr byte [x2], 3
and [x1], al
shr byte [x1], 5
mov al, [x3]
SIGNINT eax
PUTCHAR 0xa
mov al, [x2]
SIGNINT eax
PUTCHAR 0xa
mov al, [x1]
SIGNINT eax
PUTCHAR 0xa

xor eax, eax
or al, [x1]
shl byte [x2], 3
or al, [x2]
shl byte [x3], 5
or al, [x3]
SIGNINT eax
PUTCHAR 0xa
mov ebx, [x3]
cmp ebx, [x1]
JE L
PUTCHAR "N"
PUTCHAR 0xa
jmp L1
L:
PUTCHAR "Y"
PUTCHAR 0xa
L1:
FINISH
