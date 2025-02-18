%include "st_io.inc"
global _start
section .data
section .bss
a resd 1
b resd 1
section .text
_start:
mov ecx, 10
mov edx, 0
M:
GETSIG eax
cmp eax, 0 
JNE K
inc edx
K:
push eax
dec ecx
cmp ecx, 0
JNE M

mov ebp, esp
mov [a], eax
mov [b], ebx
mov eax, [ebp + 4]
mov ebx, [ebp]
mov [ebp], eax
mov [ebp + 4], ebx
mov eax, [a]
mov ebx, [b]

mov ecx, 10
L:
pop eax
SIGNINT eax
PUTCHAR ' '
dec ecx
cmp ecx, 0
JNE L
PUTCHAR 0xa
SIGNINT edx
PUTCHAR 0xa
FINISH

