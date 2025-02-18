%include "st_io.inc"
global _start
section .data
a db 11100101b
b db 10000000b
section .text
_start:
xor eax, eax
xor ebx, ebx
xor edx, edx
xor esi, esi
mov al, [a]
mov bl, [b]
mov ecx, 3
L1:
shr al, 1
rcr dl, 1
loop L1

mov ecx, 3
L:
shl bl, 1
rcl al, 1
loop L

mov ecx, 3
L2:
shl dl, 1
rcl esi, 1
loop L2

mov ecx, 3
L3:
shr esi, 1
rcr bl, 1
loop L3
SIGNINT eax
SIGNINT ebx
FINISH

