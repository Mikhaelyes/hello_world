%include "st_io.inc"
global _start
section .data
t dd 400
h dd 0
m dd 0
s dd 0
d dd ":"
section .text
_start:
mov cx, 60

mov dword eax, [t]
div cx
mov dword [s], edx
div cx
mov dword [m], edx
mov dword [h], eax

mov eax, 4
mov ebx, 1
mov edx, 2

mov ecx, h
int 0x80
mov ecx, d
int 0x80
mov ecx, m
int 0x80
mov ecx, d
int 0x80
mov ecx, s
int 0x80

mov eax, 1
mov ebx, 0
int 0x80
