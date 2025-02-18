%include "st_io.inc"
global _start
section .data
section .bss
x resd 1
section .text
_start:
mov ecx, 10
M:
GETSIG eax
push eax
dec ecx
cmp ecx, 0
JNE M

mov edx, esp
mov ebx, 0
mov esi, 0
M1:
add esi, 4
mov eax, [edx + ebx*1]
mov ecx, [edx + ebx + esi*1]
cmp eax, ecx
JE M2

add ebx, esi
cmp ebx, 36
JNE M1
sub ebx, esi
cmp ebx, 32
JE M3
add ebx, 4
mov esi, 0
jmp M1

M2:
mov al, 1
PUTCHAR '1'
PUTCHAR 0xa
FINISH

M3:
mov al, 0
PUTCHAR '0'
PUTCHAR 0xa
FINISH
