.data
s:
  .string "Soy una cadena \n"
.text
.globl main
main:
  pushq %rbp
  movq %rsp, %rbp

  movq $0, %rax     # tamaño 3 
  xorq %rax, %rax   # tamaño 7


  addq $1, %rax     # tamaño 3
  incq %rax         # tamaño 4

  subq $1, %rax     # tamaño 3
  decq %rax         # tamaño 4

  imulq $-1, %rax   # tamaño 3
  negq %rax         # tamaño 4

  movq $s, %rax     # tamaño 3
  leaq s, %rax      # tamaño 7

  popq %rax         # tamaño 8
  movq (%rsp), %rax # tamaño 1
  addq $8, %rsp     # tamaño 4

  movq %rbp, %rsp
  popq %rbp

  ret
