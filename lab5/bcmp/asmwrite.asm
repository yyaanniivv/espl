 
section .text
global asmwrite
global asmopen
global asmread
global asmclose

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
ret


asmopen:
push	ebp
mov	ebp, esp
;get the three args. char. length.

mov	ecx, [ebp+12] ; permission flags
mov	ebx, [ebp+8] ; file path
mov	eax,5 ; system call write
int	0x80 ; inturrupt and call system

pop	ebp
ret

asmread:
push	ebp
mov	ebp, esp
;get the three args. char. length.

mov	edx, [ebp+16]  ;len
mov	ecx, [ebp+12] ; buffer
mov	ebx, [ebp+8] ; file descriptor (stdout)
mov	eax,3 ; system call write
int	0x80 ; inturrupt and call system

pop	ebp
ret
