.data
s1:
  .string  "Hubo carry?  %d\n"
.text
.globl sumaC
sumaC:
  movq 16(%rsp), %rdi   # Busco 1er argumento
  movq 8(%rsp), %rsi    # Busco 2do argumento
  addq %rdi, %rsi       
  jc fin
  movq $0, %rax
  ret
fin:
  movq $1, %rax         # Hay carry
  ret


.globl main
main:
  pushq %rbx
  movq %rsp, %rbp

# Ejemplo1 de sumaC
  pushq $0xfffffffffffffff0   
  pushq $0x1
  call sumaC
  movq $s1, %rdi
  movq %rax, %rsi
  movq $0, %rax
  call printf      
  addq $16, %rsp     # Borro del stack los dos argumentos         
# Termina ej1 

# Ejemplo2 de sumaC
  pushq $0xffffffffffffffff  
  pushq $0x1
  call sumaC
  movq $s1, %rdi
  movq %rax, %rsi
  movq $0, %rax
  call printf      
  movq $0, %rax
  addq $16, %rsp    # Borro del stack los dos argumentos
# Termina ej2 

movq %rbp, %rsp
  popq %rbp
  ret

