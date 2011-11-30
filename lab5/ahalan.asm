 
section .text
global ahalan
extern puts
extern length


ahalan: 
  push ebp
  mov ebp, esp

  mov edx,eax ;strlen
  push msg    ; arg[1]
  call puts  ; function call

  ;mov ecx,msg ;message to write
  ;mov ebx,1 ;file descriptor (stdout)
  ;mov eax,4 ;system call number (sys_write)
  ;int 0x80 ;call kernel
  pop ebp
  ret

section .data

msg db 'ahalan!',0xa,0 ;our dear string
len equ $ - msg