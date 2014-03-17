.data

.text
fact:
	# a0 = n
	li $t0, 1
	bgt $a0, $t0, cont
	li $v0, 1
	jr $ra
cont:
	addi $sp, $sp, -4	#push $va 
	sw $ra, ($sp)		#
	addi $sp, $sp, -4	#push $a0
	sw $a0, ($sp)		#
	addi $a0, $a0, -1	#fact(n-1)
	jal fact		#
	#v0 = fact(n-1)
	lw $a0, ($sp)		#pop $a0
	addi $sp, $sp, 4	#
	lw $ra, ($sp)		#pop $ra
	addi $sp, $sp, 4	#
	mul $v0, $a0, $v0
	#en $v0 = fact(n-1)*n
	jr $ra, # ret

.globl main
main:
	li $a0, 10
	li $a1, 1
factr:
	li $t0, 1
	ble $a0, $t0, listo
	mul $a1, $a1, $a0
	addi $a0, $a0, -1
	j factr			#se preserva $ra
listo:
	move $v0, $a1
#print
	move $a0, $v0
	li $v0, 1
	syscall
#print
	jr $ra
