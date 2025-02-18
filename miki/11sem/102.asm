%include "st_io.inc"
global _start
section .data
d dw 0000000011000000b
section .text
_start:
mov esi, 0
mov edx, 0
cmp esi, edx
add esi, edx
pushf
pop eax
xor eax, [d]
push eax
popf

jz L
PUTCHAR '0'
PUTCHAR 0XA
jmp D
L:
PUTCHAR '1'
PUTCHAR 0XA

D:
js M
PUTCHAR '0'
PUTCHAR 0XA
FINISH
M:
PUTCHAR '1'
PUTCHAR 0XA
FINISH

