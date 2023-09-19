# COMP1521 Week 02 Tutorial
# Computes factorials using no functions (except main)

main:
	# $t0: n
	# $t1: fac
	# t2: i

	la $a0, prompt_str 	# printf("n  = ");
	li $v0, 4		
	syscall

	li $v0, 5		# scanf("%d", &n);
	syscall

	move $t0, $v0

	li FAC, 1		# int fac = 1;

loop_init:
	li $t2, 1		# int i = 1;

loop_cond:
	bgt $t2, $t0, loop_end	# if (i > n) goto loop_end;

loop_body:
	mul $t1, $t1, $t2	# fac = fac * i;

	addi $t2, 1		# i++;

	b loop_cond		# goto loop_cond;
loop_end:
	la $a0, answer_str	# printf("n! = %d\n", fac);
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