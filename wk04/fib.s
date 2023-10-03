main:

main__prologue:
	begin
	push	$ra

main__body:

	# $t0 = n
	li	$v0, 4			# syscall 4: print_string
	la	$a0, enter_number_msg	#
	syscall				# printf("Enter a number: ");

	li	$v0, 5			# syscall 5: read_int
	syscall				#
	move	$t0, $v0		# scanf("%d", &n);

	li	$v0, 4			# syscall 4: print_string
	la	$a0, fib_msg_1		#
	syscall				# printf("Fibonacci of ");

	li	$v0, 1			# syscall 1: print_int
	move	$a0, $t0		#
	syscall				# printf("%d", n);


	li	$v0, 4			# syscall 4: print_string
	la	$a0, fib_msg_2		#
	syscall				# printf(" is ");

	move	$a0, $t0		# n into $a0
	jal	fib
	move	$t2, $v0		# result of fib(n)

	li	$v0, 1			# syscall 1: print_int
	move	$a0, $t2		#
	syscall				# #printf("%d", fib(n));


	li	$v0, 11			# syscall 11: print_char
	li	$a0, '\n'		#
	syscall				# putchar('\n');

main__epilogue:
	pop	$ra
	end

	li	$v0, 0
	jr	$ra				# return 0;


########################################################################
# .TEXT <fib>
	.text
fib:

	# Args: 
	# - $a0 - int: n
	# Returns: 
	# - int - result
	#
	# Frame:	[$ra, $s0, $s1, $s2]
	# Uses: 	[$v0, $a0, $t0, $s0, $s1, $s2]
	# Clobbers:	[$v0, $a0, $t0]
	#
	# Locals:
	#   - $s0: int n
	#   - $t0: int return value
	#
	# Structure:
	#   - fib
	#     -> [prologue]
	#     -> [body]
	#	-> [fib__n_ge_2]
	#	-> [fib__epi]
	#     -> [epilogue]

fib__prologue:
	begin
	push	$ra
	push	$s0
	push	$s1
	push	$s2


fib__body:
	move	$s0, $a0	# $s0 contains n now
	bge	$s0, 2, fib__n_ge_2	#if (n >= 2) goto fib__n_ge_2;

	move	$t0, $s0	#retval = n;
	j 	fib__epi 		#goto fib__epi;
    

fib__n_ge_2:
#retval = fib(n - 1) + fib(n - 2);

	# call fib(n - 1)
	sub	$a0, $s0, 1	# argument = n-1 
	jal	fib
	move	$s1, $v0	# return value

	# call fib(n-2)
	sub	$a0, $s0, 2	# $argument = n-2 
	jal	fib
	move	$s2, $v0	# return value

	# add both to get the result
	add	$t0, $s1, $s2

fib__epi:
    #return retval;
	move	$v0, $t0



fib__epilogue:
	pop	$s2
	pop	$s1
	pop	$s0
	pop	$ra
	end

	jr	$ra				# return 0;


.data
enter_number_msg:
	.asciiz	"Enter a number: "
fib_msg_1:
	.asciiz "Fibonacci of "
fib_msg_2:
	.asciiz " is "
