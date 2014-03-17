.data 
S: .quad 0
s: .quad 0
LS: .quad 0
ls: .quad 0
STRING: .string "Hola mundo"
string: .string "mun"
print: .string "%d"
.text
.globl fuerzabruta
fuerzabruta:			
	#Guardar argumentos
	movq %rdi, S
	movq %rsi, s
	movq %rdx, LS
	movq %rcx, ls
	
	lodsb 			#guarda en al el caracter apuntado por rsi
	subq %rcx, %rdx
	movq %rdx, %rcx

lookfirst:
	repne scasb
	jne notFound 	
	#encontramos el primer caracter, guardar el estado donde encontre el caracter
	movq %rcx, %r8; movq %rdi, %r9;
	movq %rsi, %r10
	movq ls, %rcx
	decq %rcx
	repe cmpsb
	je found
	movq %r8, %rcx; movq %r9, %rdi
	movq %r10, %rsi
	jmp lookfirst
notFound:
	movq $-1, %rax
	ret
found:
	movq %r9, %rax	
	movq S, %rcx
	subq %rcx, %rax
	ret
