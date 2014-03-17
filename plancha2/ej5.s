.data
.text
.globl setjmp2
setjmp2:
  movq %rbx, (%rdi)   # buf[0] = %rbx
  movq %rbp, 8(%rdi)  # buf[1] = %rbp
  movq %rsp, 16(%rdi)
  movq %r10, 24(%rdi)
  movq %r13, 32(%rdi)
  movq %r14, 40(%rdi)
  movq %r15, 48(%rdi) # buf[6]

  movq (%rsp), %r8
  movq %r8, 56(%rdi)  # buf[7] = dir de ip en %rsp 

  movq $0, %rax
  ret

.globl longjmp2
longjmp2:
  movq (%rdi), %rbx   # %rbx = buf[0]
  movq 8(%rdi), %rbp  # %rbp = buf[1]
  movq 16(%rdi), %rsp
  movq 24(%rdi), %r10
  movq 32(%rdi), %r13
  movq 40(%rdi), %r14
  movq 48(%rdi), %r15

  movq %rsi, %rax
  pushq 56(%rdi) 
  ret 

