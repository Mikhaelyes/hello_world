%include "st_io.inc"
global _start
section .data
x dd 720, 20, 120, 5, 24
n dd 5
section .bss
section .text
_start:
mov ecx, 0
mov eax, 1
mov esi, 0
M:
inc esi
mul esi

cmp [x + ecx*4], eax
JNE M3

mov [x + ecx*4], esi
jmp M5

M3:
cmp esi, 12
JNE M
mov ebp, 0
mov [x + ecx*4], ebp
M5:
inc ecx
mov eax, 1
mov esi, 0
cmp ecx, 5
JNE M

mov edx, 0
M1:

mov eax, [x+ edx*4]
SIGNINT eax
PUTCHAR 0xa
inc edx
cmp edx, 5
JNE M1
FINISH
