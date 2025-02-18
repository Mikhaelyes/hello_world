%include "st_io.inc"
global _start
section .data
section .bss
d resb 1
section .text
_start:
mov ax, 7
xor ebx, ebx
mov ecx, 16
M:
shl ax, 1
JNC L
inc ebx
L:
loop M
SIGNINT ebx
PUTCHAR 0XA
FINISH

