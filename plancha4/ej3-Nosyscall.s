# Realizado por jagretti y lfigueroa
.data
.text
.globl main
main:
	li $t4, 0xffff0008
	li $t0, 0xffff0000
	li $a3, 0
leer:
	lw $t1, ($t0)
	andi $t1, $t1, 1
	bnez $t1, go
	b leer

go:
	li $t2, 0xffff0004
	lb $t5, ($t2)

	beq $t5, 'U', fin
	beq $t5, 'A', mas1	

mas1:
  add $a3, $a3, 1
  j leer

fin:
  li $v0, 1
  move $a0, $a3
  syscall
  jr $ra

