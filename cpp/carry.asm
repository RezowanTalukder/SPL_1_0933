.data
	msg1: .asciiz "Enter the first number: "
	msg2: .asciiz "\nEnter the second number: "
	mgs3: .asciiz "\nCarry 0"
	mgs4: .asciiz "\nCarry 1"
.text
	li $v0,4
	la $a0,msg1
	syscall
 
	li $v0,5
	syscall
	move $t1,$v0
 
	li $v0,4
	la $a0,msg2
	syscall
 
	li $v0,5
	syscall
	move $t2,$v0
	
	Addu $t3 $t1 $t2
	
	#li $v0 5
	#move $a0 $t3
	#syscall
	
	blt $t3 $t1 carry1
	blt $t3 $t2 carry1
	j print0
	
	print0:
		#carry 1
		li $v0 4
		la $a0 mgs3
		syscall
		
		li $v0 10
		syscall
		
	carry1:
		#carry 0
		li $v0 4
		la $a0 mgs4
		syscall
		
		li $v0 10
		syscall
		