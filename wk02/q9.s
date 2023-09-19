# COMP1521 Week 02 Tutorial
# Computes factorials using no functions (except main)

main:
	# $t0: n
	# $t1: fac
	# t2: i

	la $a0, prompt_str
	li $v0, 4
	syscall

	li $v0, 5
	syscall

	move $t0, $v0

	li $t1, 1

loop_init:
	li $t2, 1

loop_cond:
	bgt $t2, $t0, loop_end

loop_body:
	mul $t1, $t1, $t2

	addi $t2, 1

	b loop_cond
loop_end:
	la $a0, answer_str
	li $v0, 4
	syscall

	move $a0, $t1
	li $v0, 1
	syscall

	li $a0, '\n'
	li $v0, 11
	syscall

	jr $ra

	.data
prompt_str:
	.asciiz "n  = "
answer_str:
	.asciiz "n! = "