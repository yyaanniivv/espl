section .text
    global _start ;must be declared for linker (ld)
    global asmwrite
    global length
    global innerWhileBody

    extern theOtherMain ; the external function
    extern prsym

_start: ;tell linker entry point

  mov edx, esp 
  add edx, 4
  push edx
  mov edx, [edx-4] ;esp+4
  push edx

;  mov eax,esp  ;esp = argc
;  add eax,4    ;eax is on argv  address
;  push eax     ; push argv pointer in to stack
;  push DWORD [esp+4] ;push argc in to stack

  call theOtherMain

  mov eax,1 ;system call number (sys_exit)
  int 0x80 ;call kernel



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


length:
  push ebp
  mov ebp, esp
  mov eax, -1
.L2:
  add eax, 1
  mov ebx, eax

  add ebx, [ebp+8]
  movzx ebx, BYTE [ebx]
  test bl, bl
  jne .L2
  pop ebp
  ret

innerWhileBody:
  push ebp
  mov ebp, esp
  mov eax, [ebp+8]
  mov eax, [eax]
  sub eax, 32
  push eax
  call prsym
  
  inc DWORD [ebp+16]      ; inc z  - z++
  mov edx, [ebp+16] ;edx = z
  add edx, [ebp+12] ;edx = & word[z] - pointer
  movzx edx, BYTE [edx] ;  edx = word[z] - char
  mov [ebp+8], edx ;change c's value
  pop ebp
  ret
  ;mov	eax,1
  ;int	0x80

;;;stack view:
;;stack [[argv1, argv0 , argc  ($argv0 )  ($argc) TOS (TopOfStack)
;
;davids normal func 
;mov eax, esp
;add eax. 4
;push eax
;push DWORD [esp+4]
;call main
;
; davids special func
;LEA eax, [esp+4] 
;push eax
