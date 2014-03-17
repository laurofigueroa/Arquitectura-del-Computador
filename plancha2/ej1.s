.data
n: .long 0x000fffff
S: .string "Cantidad de bits en 1 = %ld \n"
.text
.globl main
main:
  movq $0, %rax
  movq $0, %rcx
loop:
  incq %rcx
  roll  n
  adcq $0, %rax
  cmpq $32, %rcx
  jne loop
  movq %rax, %rsi
  movq $S, %rdi
  movq $0, %rax
  call printf
  ret

  
