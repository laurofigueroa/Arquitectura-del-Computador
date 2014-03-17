#hecho por lfigueroa y jagretti
.data

a1: .float 1.0
b1: .float 2.0
c1: .float 3.0
d1: .float 1.0
e1: .float 4.0
f1: .float 9.0
g1: .float 1.0
h1: .float 8.0
i1: .float 27.0
t1: .float 1.0
t2: .float 1.0
t3: .float 1.0
x1: .float 0.0 
x2: .float 0.0
x3: .float 0.0

.text
cramer:
  addi $sp, $sp, -4 
  sw $ra, ($sp)
    
  l.s $f0, a1
  l.s $f2, b1
  l.s $f4, c1
  l.s $f6, d1
  l.s $f8, e1
  l.s $f10, f1
  l.s $f12, g1
  l.s $f14, h1
  l.s $f16, i1
    
  jal determinante
  mov.s $f30, $f18 
   
  l.s $f0, t1
  l.s $f2, t2
  l.s $f4, t3
    
  jal determinante
  div.s $f18, $f18, $f30
  s.s $f18, x1
    
  l.s $f0, a1
  l.s $f2, b1
  l.s $f4, c1
  l.s $f6, t1
  l.s $f8, t2
  l.s $f10, t3
    
  jal determinante
  div.s $f18, $f18, $f30
  s.s $f18, x2
    
  l.s $f6, d1
  l.s $f8, e1
  l.s $f10, f1
  l.s $f12, t1
  l.s $f14, t2
  l.s $f16, t3
        
  jal determinante
  div.s $f18, $f18, $f30
  s.s $f18, x3
    
  lw $ra,($sp)   
  addi $sp,$sp,4
    
  jr $ra	

determinante:  
  mul.s $f18, $f0, $f8
	mul.s $f18, $f18, $f16

	mul.s $f20, $f2, $f10
	mul.s $f20, $f20, $f12

	mul.s $f22, $f6, $f14
	mul.s $f22, $f22, $f4

	mul.s $f24, $f12, $f8
	mul.s $f24, $f24, $f4

	mul.s $f26, $f14, $f10
	mul.s $f26, $f26, $f0

	mul.s $f28, $f6, $f2
	mul.s $f28, $f28, $f16

	add.s $f18, $f18, $f20
	add.s $f18, $f18, $f22

	add.s $f24, $f24, $f26
	add.s $f24, $f24, $f28

	sub.s $f18, $f18, $f24
  
  jr $ra 

.globl main
main:
  addi $sp,$sp,-4
  sw $ra,($sp)

  jal cramer
  
  li $v0,2 #print_float
  l.s $f12,x1
  syscall

  li $v0,2    
  l.s $f12,x2
  syscall 
  
  li $v0,2   
  l.s $f12,x3
  syscall
  
  lw $ra,($sp)    
  addi $sp,$sp,4

  jr $ra
