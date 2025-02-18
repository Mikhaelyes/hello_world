global _start
section .bss
c resb 1
section .text
_start:
mov eax, 3
mov ebx, 2
mov ecx, c
mov edx, 1
int 0x80

mov eax, 4
mov ebx, 1
mov ecx, c
mov edx, 1
int 0x80

mov eax, 1
mov ebx, 0
int 0x80
