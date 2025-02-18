%include "st_io.inc"
global _start
section .data
a dd 1, -5, 4, 3
n dd 4
section .text

PROGA:
mov ebp, esp
mov ebx, [ebp+4]  ; =a+12
mov eax, [ebx]  ; =3
mov esi, 1
mov edi, [ebp+4] 
M:
scasd
JLE M2
mov ebx, edi
mov eax, [ebx]
M2:
loop M
SIGNINT eax
PUTCHAR 0xa
ret

_start:
mov ecx, [n]
mov eax, a
L:
push eax
add eax, 4
dec ecx
cmp ecx, 0
JNE L
mov ecx, [n]
call PROGA
FINISH


