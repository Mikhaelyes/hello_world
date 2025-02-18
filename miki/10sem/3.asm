%include "st_io.inc"
global _start
section .data
section .bss
section .text
_start:
mov ax, 3875
mov ecx, 8
M:
rol ax, 1
loop M
mov ecx, 0
mov cx, ax
SIGNINT ecx
PUTCHAR 0xa
FINISH
