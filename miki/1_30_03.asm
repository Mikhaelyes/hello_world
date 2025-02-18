%include "st_io.inc"
global _start
section .data
section .bss
x resd 1
section .text
_start:

GETUN dword [x]
mov ecx, 0
mov esi, 10
mov eax, [x]

L:
inc ecx
mov edx, 0
div esi
cmp eax, 0
jne L

SIGNINT ecx
PUTCHAR 0xa
FINISH



