%include "st_io.inc"
global _start
section .data
d dw 0000000010000000b
section .text
_start:
pushf
pop eax
xor eax, [d]
push eax
popf
js M
PUTCHAR '0'
PUTCHAR 0XA
FINISH
M:
PUTCHAR '1'
PUTCHAR 0XA
FINISH 
