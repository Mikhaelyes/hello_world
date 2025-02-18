%include "st_io.inc"
global _start
section .data
section .bss
section .text
_start:
mov ax, 15
mov ecx, 16
M:
shl ax, 1
jc L
loop M
PUTCHAR "N"
PUTCHAR "O"
PUTCHAR 0xa
L:
jc K
PUTCHAR "0"
jmp X
K:
PUTCHAR "1"
X:
shl ax, 1
loop L
PUTCHAR 0xa
FINISH
