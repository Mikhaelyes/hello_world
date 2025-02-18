%include "st_io.inc"
global _start
section .data
section .bss
section .text
_start:
mov al, 00101010b
mov bl, 10101010b
xor al, bl
mov ecx, 3
M:
shl al, 1
JC M1
loop M
PUTCHAR "Y"
PUTCHAR "E"
PUTCHAR 0xa
FINISH

M1:
PUTCHAR "N"
PUTCHAR "O"
PUTCHAR 0xa
FINISH
