%include "st_io.inc"
global _start
section .data
a dd -1, -5, -10, 0
n dd 4
section .text

QWQ:
pop ecx
mov edx, esp
mov eax, [edx]
mov edi, edx
M:
PUTCHAR "1"
add edi, 4
scasd
jle M1
mov eax, edi
mov eax, [eax]
M1:
loop M


_start:
mov ecx, [n]
mov eax, a
L:
push eax
add eax, 4
loop L
mov ecx, [n]
push ecx
call QWQ
FINISH
