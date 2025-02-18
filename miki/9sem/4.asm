%include "st_io.inc"
global _start
section .data
section .bss
a resd 1
b resd 1
c resd 1
section .test

sub:
mov ebp, esp
mov eax, [ebp + 40]
sub eax, [ebp + 36]
SIGNINT eax
PUTCHAR ' '
ret

_start:
GETSIG eax
push eax
GETSIG eax
push eax
pushad
call sum
call sub
popad
FINISH


sum:
mov ebp, esp
mov eax, [ebp + 40]
add eax, [ebp + 36]
SIGNINT eax
PUTCHAR ' '
ret

