#hecho por lfigueroa y jagretti
.data
a1: .float 5.0
b1: .float 6.6 
c1: .float 7.8
d1: .float 2.4
e1: .float 9.4
f1: .float 9.0
g1: .float 1.0
h1: .float 5.0
i1: .float 7.0

.text
determinante:
  l.s $f0, a1
  l.s $f2, b1
  l.s $f4, c1
  l.s $f6, d1
  l.s $f8, e1
  l.s $f10, f1
  l.s $f12, g1
  l.s $f14, h1
  l.s $f16, i1

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

  li $v0, 2 
  mov.s $f12,$f18
  syscall
  
  jr $ra 

.globl main
main:
  jal determinante 
  jr $ra
