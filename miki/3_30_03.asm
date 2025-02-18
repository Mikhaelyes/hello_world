%include "st_io.inc"
global _start
section .data
section .bss
x resw 10
a resd 1
b resd 1
h resd 1
section .text
_start:
GETUN dword [a]
PUTCHAR 0xa
GETUN dword [b]
PUTCHAR 0xa
GETUN dword [h]
PUTCHAR 0xa
mov dword ebx, [a]
mov edx, 0
mov esi, 3
L:
add ebx, [h]
mov eax, ebx
div esi
SIGNINT edx
PUTCHAR ' '
mov edx, 0
cmp ebx, [b]
JG L1
jmp L
L1:

PUTCHAR 0xa
FINISH
