global _start
section .data
section .bss
x resw 1
section .text
_start:
mov dword [x], 1
mov eax, 4
mov ebx, 1
mov ecx, x
mov edx, 2
int 0x80

mov eax, 1
mov ebx, 0
int 0x80

