%include "st_io.inc"
global _start
section .data
x dd 1, -2, 3, -4, -5
y dd 0, 0
z dd 0, 0
section .bss
section .text
_start:
mov ecx, 5
mov esi, -1
M:
inc esi
mov eax, [x + esi*4]
push eax
loop M

mov ecx, 5
mov esi, -1
mov edx, 0
mov ebp, esp
M1:
inc esi
mov eax, [ebp + esi*4]
cmp eax, 0
JG M2
mov [y + edx*4], esi
inc edx
cmp edx, 2
JE M3
M2:
loop M1
PUTCHAR 'N'
PUTCHAR 'O'
PUTCHAR 0xa
FINISH

M3:
mov ecx, -1
M8:
inc ecx
mov eax, [ebp + ecx*4]
SIGNINT eax
PUTCHAR ' '
cmp ecx, 5
JNE M8
PUTCHAR 0xa

mov ecx, -1
M9:
inc ecx
mov eax, [y + ecx*4]
SIGNINT eax
PUTCHAR ' '
cmp ecx, 1
JNE M9
PUTCHAR 0xa

mov esi, [y]
mov eax, [ebp +esi*4]
mov [z], eax
mov esi, [y + 4]
mov eax, [ebp + esi*4]
mov [z + 4], eax 

mov eax, [z + 4]
mov edx, [y]
mov [ebp + edx*4], eax

mov eax, [z]
mov edx, [y + 4]
mov [ebp + edx*4], eax

mov ecx, -1
M5:
inc ecx
pop eax
mov [x + ecx*4], eax
SIGNINT eax
PUTCHAR ' '
cmp ecx, 5
JNE M5
PUTCHAR 0xa

FINISH
