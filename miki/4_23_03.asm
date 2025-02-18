%include "st_io.inc"
global _start
section .data
da dw "DA", 0xA, 0
no dw "NO", 0xA, 0
a1 dd 100
b1 dd 20
c1 dd 30
section .text

_start:
mov eax, [a1]
add dword eax, [b1]
cmp [c1], eax
jbe L1
jmp L5

L1:
mov bx, 0
inc bx

mov eax, [b1]
add dword eax, [c1]
cmp [a1], eax
jbe L2
jmp L5

L2:
inc bx

mov eax, [c1]
add dword eax, [a1]
cmp [b1], eax
jbe L3
jmp L5

L3:
inc bx

cmp bx, 3
je L4
jmp Lend

L4:
mov eax, 4
mov ebx, 1
mov ecx, da
mov edx, 4
int 0x80
jmp Lend

L5:
mov eax, 4
mov ebx, 1
mov ecx, no
mov edx, 4
int 0x80

Lend:
mov eax, 1
mov ebx, 0
int 0x80

