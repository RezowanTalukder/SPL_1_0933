.data
	mgs1: .asciiz "\nEnter an integer number\n"

.text

	li $v0,4
	la $a0,mgs1
	syscall
	
	li $v0 5
	syscall
	move $t1 $v0
	
	getRem:
		div $t2 $t1 2
		mul $t3 $t2 2
		
		beq $t3 $t1 Zero
		bne $t3 $t1 One
		j getRem
		
	Zero: 
		li $v0 1
		move $a0 $zero
		syscall
		move $t1 $t2
		beq $t1 $zero Exit
		j getRem
	
	One:
		li $v0 1
		li $s0 1
		move $a0 $s0
		syscall
		move $t1 $t2
		beq $t1 $zero Exit
		j getRem
		
	
	Exit:
		li $v0 10
		syscall
		
		