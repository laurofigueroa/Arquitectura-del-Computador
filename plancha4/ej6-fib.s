#hecho lfigueroa y jagretti
.data
.text
.globl main
main:
	li $v0, 5
	syscall
	move $a0, $v0
	jal fibonacci
	move $a0, $v0
	li $v0, 1
	syscall
	li $v0,10
	syscall
	jr $ra

fibonacci:
	li $t0, 2
	bltu $a0,$t0, menor_a_dos
	addi $sp, $sp, -8
	sw $ra, 4($sp)
	sw $a0, 0($sp)
	addi $a0,$a0, -1
	jal fibonacci
	move $t1, $v0
	lw $ra, 4($sp)
	lw $a0, 0($sp)
	addi $sp, $sp, 8
	addi $sp, $sp, -8
	sw $ra, 4($sp)
	sw $t1, 0($sp)
	addi $a0,$a0, -2
	jal fibonacci
	move $t2, $v0
	lw $ra, 4($sp)
	lw $t1, 0($sp)
	addi $sp,$sp, 8
	add $v0, $t1,$t2
	jr $ra

menor_a_dos:
	move $v0, $a0
	jr $ra
