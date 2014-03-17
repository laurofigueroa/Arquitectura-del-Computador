#hecho lfigueroa y jagretti
.data
.text
factr:
  li $t0,1
  ble $a0,$t0,go
  mul $a1,$a1,$a0
  addi $a0,$a0,-1
  j factr

fibr:
  li $t0, 1
  ble $a0, $t0, go
  add $a3, $a1, $a2
  move $a1, $a2
  move $a2, $a3    
  addi $a0, $a0, -1
  j fibr

go:
  move $v0,$a1
  jr $ra
    
.globl main
main:
  li $a0, 8
  li $a1, 1
  jal factr
  move $a0, $v0
  li $v0, 1
  syscall

  li $a0, 8
  li $a1, 1
  li $a2, 1
  jal fibr
  move $a0, $v0
  li $v0, 1
  syscall
  li $v0, 10
  syscall

  jr $ra                                 
