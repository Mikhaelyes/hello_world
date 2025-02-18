%include "st_io.inc"
global _start
section .data
section .bss
a resd 1
b resd 1
c resd 1
section .test

sub:
mov eax, [a]
sub eax, [b]
mov [c], eax
SIGNINT eax
ret

_start:
GETSIG eax
mov [a], eax
GETSIG eax
mov [b], eax
call sum
call sub
FINISH


sum:
mov eax, [a]
add eax, [b]
mov [c], eax
SIGNINT eax
ret
