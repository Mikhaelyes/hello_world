mov eax, 4
mov edi, a
mov ecx, 6
M:
scasd
JNE L
mov [edi], 77
L:
loop M
