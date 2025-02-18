%include "st_io.inc"
global _start
section .data
section .bss
section .text
_start:
mov eax, 0
mov ecx, 1
mov edx, 1
mov esi, 1
L:
inc eax
add edx, ecx
mov ecx, esi
mov esi, edx
cmp eax, 10
je L1
jmp L

L1:
SIGNINT edx
PUTCHAR 0xa

FINISH
