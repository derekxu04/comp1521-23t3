# Prints the square of a number

main:
	# $t0: x
	# $t1: y

	la $a0, prompt_str	# printf("Enter a number: ");
	li $v0, 4
	syscall

	li $v0, 5		# scanf("%d", &x);
	syscall
	move $t0, $v0

	mul $t1, $t0, $t0	# y = x * x;

	li $v0, 1		# printf("%d\n", y);
	move $a0, $t1
	syscall

	li $a0, '\n'
	li $v0, 11
	syscall

	jr $ra			# return 0;

	.data
prompt_str:
	.asciiz "Enter a number: "