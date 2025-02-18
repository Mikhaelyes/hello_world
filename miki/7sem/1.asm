%include "st_io.inc"
global _start
section .data
mas1 dd 1, 2, 3, 4, 5, 6, 7, 8, 9
mas2 dd 11, 12, 13, 14, 15, 16, 17, 18, 19
section .bss
section .text
_start:
mov ecx, 9
mov esi, 0
mov edx, 0
M:
mov eax, [mas2 + ebx + esi*4]
add [mas1 + ebx + esi*4], eax
mov eax, [mas1 + ebx + esi*4]
inc esi
SIGNINT eax
PUTCHAR ' '
cmp esi, 3
JNE M3
mov esi, 0
add ebx, 12
PUTCHAR 0xa

M3:
dec ecx
cmp ecx, 0
JNE M

FINISH
