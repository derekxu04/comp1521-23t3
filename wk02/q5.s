# Squares a number, unless it is too big for a 32-bit register.
# If it is too big, prints an error message instead.

# Prints the square of a number

SQUARE_MAX = 46340

main:
	# $t0: x
	# $t1: y

	la $a0, prompt_str	# printf("Enter a number: ");
	li $v0, 4
	syscall

	li $v0, 5
	syscall
	move $t0, $v0

	ble $t0, SQUARE_MAX, square_small_enough

	la $a0, too_big
	li $v0, 4
	syscall

	j epilogue

square_small_enough:
	mul $t1, $t0, $t0

	li $v0, 1
	move $a0, $t1
	syscall

	li $a0, '\n'
	li $v0, 11
	syscall

epilogue:

	jr $ra

	.data
prompt_str:
	.asciiz "Enter a number: "
too_big:
	.asciiz "square too big for 32 bits\n"