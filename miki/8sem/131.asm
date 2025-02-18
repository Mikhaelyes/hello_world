%include "st_io.inc"
global _start
section .data
section .bss
x resd 1
y resd 1
x1 resd 1
y1 resd 1
section .text
_start:
GETSIG eax
mov [x], eax
GETSIG eax
mov [y], eax

mov eax, [x]
mul eax
mov [x1], eax
mov eax, [y]
mul eax
mov [y1], eax

add eax, [x1]
cmp eax, 2
JG M
mov eax, [x]
cmp eax, 0
JG M1
mov eax, [y]
cmp eax, 0
JG M2
PUTCHAR '3'
FINISH
M2:
PUTCHAR '4'
FINISH
M1:
mov eax, [y]
cmp eax, 0
JG M3
PUTCHAR '2'
FINISH
M3:
PUTCHAR '1'
FINISH

M:
PUTCHAR 'N'
PUTCHAR 'O'
PUTCHAR 0xa
FINISH
