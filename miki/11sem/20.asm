%include "st_io.inc"
global _start
section .data
d dd 2, 5, 1, -1, 1, -3
n dd 6
section .text
PROGA:
mov ebp, esp
mov ecx, [ebp +4]
dec ecx
mov ebx, [ebp+8]
mov eax, [ebx]
mov edi, [ebp+12]
M1:
scasd
JLE M3
mov ebx, edi
sub ebx, 4
mov eax, [ebx]
M3:
loop M1
mov dword [ebx], 700
ret 0

_start:
mov ecx, [n]
mov eax, ecx
dec eax
mov ebx, 4
mul ebx
add eax, d
M:
push eax
sub eax, 4
loop M
mov ecx, [n]
push ecx
call PROGA

pop ecx
SIGNINT eax
PUTCHAR 0xa
M4:
pop ebx
mov eax, [ebx]
SIGNINT eax
PUTCHAR " "
dec ecx
cmp ecx, 0
JNE M4

PUTCHAR 0xa
FINISH
