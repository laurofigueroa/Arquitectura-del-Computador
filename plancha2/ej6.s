.data
.text
.globl abs_short2
abs_short2:
  # a = a ^ (a>>16) - (a>>16)
  cwd   #convierte el signo de 16 bits a uno de 32 formado por dx:ax   
  xorw %dx, %ax
  subw %dx, %ax
  ret
