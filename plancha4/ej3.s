# Realizado por jagretti y lfigueroa
.data
m: .asciiz "Hola mundo \n"
s: .half 0
.text
.globl main
main:
	li $v0, 8
	la $a0, s
	li $a1, 2
	li $a3, 0
loop:	
	syscall
	lb $t5, s
	beq $t5, 'U', fin 
	beq $t5, 'A', mas1
	j loop
mas1:
	add $a3, $a3, 1
	j loop
fin:
	li $v0, 1
	move $a0, $a3
	syscall
	jr $ra



