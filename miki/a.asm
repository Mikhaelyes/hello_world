global _start
section .data
ms db "Hello world", 0xA, 0
lms equ $ -ms
section .text
_start:
mov eax, 4
mov ebx, 1
mov ecx, ms
mov edx, lms
int 0x80
mov eax, 1
mov ebx, 0
int 0x80
