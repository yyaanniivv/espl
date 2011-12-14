 
section .text
global asmwrite

asmwrite:
push	ebp
mov	ebp, esp
;get the three args. char. length.

mov	edx, [ebp+16]  ;len
mov	ecx, [ebp+12] ; pointer to string
mov	ebx, [ebp+8] ; file descriptor (stdout)
mov	eax,4 ; system call write
int	0x80 ; inturrupt and call system

pop	ebp
mov	eax,1
int	0x80
