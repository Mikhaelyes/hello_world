%include "st_io.inc"
global _start
section .data
section .bss
section .text
_start:
mov esi, 16
xor ecx, ecx	;ax = 0
xor dx, dx		
not dx		;dx = 1
xor bx, bx	;bx = 0
M:
GETSIG ecx
cmp ecx, 9
JE M1
cmp ecx, 1
JE M2
shl bx, 1
rcl ax, 1
jmp M3
M2:
shl dx, 1
rcl ax, 1
M3:
dec esi
cmp esi, 0
JNE M

M1:
SIGNINT eax
PUTCHAR 0xa
FINISH
