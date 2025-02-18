%include "st_io.inc"
global _start
section .data
section .bss
x resb 1
section .text
_start:
mov dh, 1
mov ax, 1
mov ecx, 1
L:
mov [x], dh
inc dh
mov eax, 4
mov ebx, 1
mov ecx, x
mov edx, 1
int 0x80
mul dx

JNO L

GETUN dword [x]
mov eax, 1
mov ebx, 0
int 0x80
