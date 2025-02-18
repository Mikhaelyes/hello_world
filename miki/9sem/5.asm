%include "st_io.inc"
extern fac
global _start
section .data
section .bss
n resd 1
section .text
_start:
GETSIG eax
pushad
push eax
call fac
popad
FINISH
