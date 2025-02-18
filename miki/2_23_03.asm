%INCLUDE "st_io.inc"
global _start
section .data
a db 6
b db 5
ms db "Da", 0xA, 0
lms equ $-ms
ccc db "NO", 0xA, 0
cccc equ $-ccc
section .text

_start:
mov al, [a]
mov bl, [b]

cmp al, bl
jle L1

mov eax, 4
mov ebx, 1
mov edx, cccc
mov ecx, ccc
int 0x80

jmp L2

L1:
mov eax, 4
mov ebx, 1
mov edx, lms
mov ecx, ms
int 0x80

L2:
mov eax, 1
mov ebx, 0
int 0x80
