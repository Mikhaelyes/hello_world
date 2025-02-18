include st_io.inc
global _start
section .data
a dw 5
b dw 6
i dw 1
_start:
mov a, eax
cmp eax, b
jle L1

add i -1
jmp L2

L1: 
add i 1

L2:
PRINT i
FINISH
