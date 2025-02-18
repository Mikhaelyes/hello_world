%include "st_io.inc"
global _start
section .data
l dd 0
b dd 5
c dd 0
yes dw "YES", 0xA, 0
no dw "NO", 0xA, 0
section .text 
_start:
mov eax, 3
mov ebx, 2
mov ecx, l
mov edx, 2
int 0x80
mov dx, 0
mov ax, [l]
mov bx, 10

L1:
cmp dx, [b]
je L
mov dx, 0
div bx
cmp ax, [c]
je L2
jmp L1


L:
mov eax, 4
mov ebx, 1
mov ecx, no
mov edx, 4
int 0x80
jmp L3

L2:
mov eax, 4
mov ebx, 1
mov ecx, yes
mov edx, 4
int 0x80

L3:
mov eax, 1
mov ebx, 0
int 0x80

