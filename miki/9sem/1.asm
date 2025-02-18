%include "st_io.inc"
global _start
section .data
section .bss
a resd 1
b resd 1
c resd 1
section .text
_start:
GETSIG EAX
mov [a], eax
GETSIG EAX
mov [b], eax
JMP M
M1:
FINISH


M:
mov eax, [a]
add eax, [b]
mov [c], eax
SIGNINT eax
JMP M1
