%include "st_io.inc"
global fac
section .text
fac:
mov ebp, esp
mov eax, 1
mov esi, [ebp + 4]
SIGNINT esi
PUTCHAR 0xa
M:
mul esi
dec esi
cmp esi, 1
JNE M
SIGNINT eax
ret 4
