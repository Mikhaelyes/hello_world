%include "st_io.inc"
global _start
section .data
x dd 2, 1, 3, 4, 8, 6, 7, 8, 9
y dd 0, 0, 0
z dd 0, 0, 0
section .bss
max resd 1
min resd 1
section .text
_start:
mov ecx, 9
mov esi, -1
mov ebx, 0
mov edx, 0
M:
inc esi
mov eax, [x + edx + esi*4]
cmp eax, ebx
JLE M1
mov ebx, eax
mov [max], edx
M1:
cmp esi, 2
JNE M2
mov esi, -1
add edx, 12
M2:
loop M


mov ecx, 9
mov esi, -1
mov ebx, 40000
mov edx, 0
L:
inc esi
mov eax, [x + edx + esi*4]
cmp eax, ebx
JG L1
mov ebx, eax
mov [min], edx
L1:
cmp esi, 2
JNE L2
mov esi, -1
add edx, 12
L2:
loop L

mov eax, [max]
SIGNINT eax
PUTCHAR ' '
mov eax, [min]
SIGNINT eax 
PUTCHAR 0xa

mov ecx, 3
mov edx, [max]
mov esi, -1
L4:
inc esi
mov eax, [x + edx + esi*4]
mov [y + esi*4], eax
loop L4

mov ecx, 3
mov edx, [max]
mov ebp, [min]
mov esi, -1
L5:
inc esi
mov eax, [x + ebp + esi*4]
mov [x + edx +esi*4], eax
loop L5

mov ecx, 3
mov edx, [min]
mov esi, -1
L6:
inc esi
mov eax, [y + esi*4]
mov [x + edx + esi*4], eax
loop L6

mov esi, -1
L7:
inc esi
mov eax, [x + esi*4]
SIGNINT eax
PUTCHAR ' '	
cmp esi, 8
JNE L7

FINISH
