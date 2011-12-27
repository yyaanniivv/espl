section .text
global _start

extern main

_start:
  mov edx, esp ; TOS - TopOfSstack location
  mov edx, [edx+4] ; [argv argc [main] TOS -> [ argv argc &argv &argc
  push edx
  mov edx, [edx+4]
  push edx
  
  call main
  mov ebx,eax
  mov eax,1
  int 0x80
