%include "st_io.inc"
global _start
section .data
section .bss
section .text
_start:
xor eax, eax
xor ebx, ebx
mov al, 01110100b
mov bl, 01010110b
shr al, 4		;0000 0111
shl bl, 4		;0110 0000
mov ecx, 4
M:
shl bl, 1
rcl al, 1
loop M
xor ecx, ecx
mov cl, al
SIGNINT ecx
PUTCHAR 0xa
FINISH
