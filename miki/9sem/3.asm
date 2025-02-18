%include "st_io.inc"
global _start
section .data
section .bss
a resd 1
b resd 1
c resd 1
section .test

sub:
sub eax, ebx
SIGNINT eax
PUTCHAR ' '
ret

_start:
GETSIG eax
GETSIG ebx
pushad
call sum
popad
pushad
call sub
popad
PUTCHAR 0xa
FINISH


sum:
add eax, ebx
SIGNINT eax
PUTCHAR ' '
ret

