	.file	"atod.c"
	.intel_syntax noprefix
	.text
.globl atod
	.type	atod, @function
atod:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	DWORD PTR [ebp-4], 0
	mov	DWORD PTR [ebp-8], 0
	jmp	.L2
.L3:
	mov	edx, DWORD PTR [ebp-4]
	mov	eax, edx
	sal	eax, 2
	add	eax, edx
	add	eax, eax
	mov	DWORD PTR [ebp-4], eax
	mov	eax, DWORD PTR [ebp-8]
	add	eax, DWORD PTR [ebp+8]
	movzx	eax, BYTE PTR [eax]
	movsx	eax, al
	sub	eax, 48
	add	DWORD PTR [ebp-4], eax
	add	DWORD PTR [ebp-8], 1
.L2:
	mov	eax, DWORD PTR [ebp-8]
	add	eax, DWORD PTR [ebp+8]
	movzx	eax, BYTE PTR [eax]
	test	al, al
	jne	.L3
	mov	eax, DWORD PTR [ebp-4]
	leave
	ret