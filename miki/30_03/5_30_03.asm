%include "st_io.inc"
global _start
section .data
mas dd 1, 30, -1, 0, 6, 10
section .bss
n resd 1
section .text
_start:
mov ebx, 0
mov ecx, 6
mov esi, 0
A:
inc esi
cmp [mas + esi * 4 - 4], ebx
JE A1 
loop A
mov eax, 5
mov [n], eax
jmp short A2

A1:
add esi, 1
mov [n], esi
A2:



mov ecx, [n]
mov esi, 0
mov eax, [mas]
M:
inc esi
cmp eax, [mas + esi * 4]
JL M2

M1:

loop M
jmp short M3
M2:
mov eax, [mas + esi * 4]

jmp short M1

M3:
PUTCHAR 'm'
PUTCHAR 'a'
PUTCHAR 'x'
PUTCHAR ' '
SIGNINT eax
PUTCHAR 0xa



mov ecx, [n]
mov esi, 0
mov eax, [mas]
L:
inc esi
cmp eax, [mas + esi * 4]
JG L2

L1:

loop L
jmp short L3
L2:
mov eax, [mas + esi * 4]

jmp short L1

L3:
PUTCHAR 'm'
PUTCHAR 'i'
PUTCHAR 'n'
PUTCHAR ' '
SIGNINT eax
PUTCHAR 0xa



mov eax, 1
add [n], eax
mov ecx, [n]
mov esi, -1
mov eax, 0
mov ebx, 0
mov edx, 0
E:
inc esi
cmp [mas + esi * 4], ebx
JL E2

E1:

loop E
jmp short E3

E2:
add eax, [mas +esi * 4]
inc edx
jmp short E1

E3:
PUTCHAR 's'
PUTCHAR 'u'
PUTCHAR 'm'
PUTCHAR ' '
SIGNINT eax
PUTCHAR ' '
PUTCHAR 'k'
PUTCHAR 'o'
PUTCHAR 'l'
PUTCHAR ' '
SIGNINT edx
PUTCHAR 0xa

FINISH
