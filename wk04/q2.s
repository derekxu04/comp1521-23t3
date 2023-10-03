# This program prints out a danish flag, by
# looping through the rows and columns of the flag.
# Each element inside the flag is a single character.
# (i.e., 1 byte).
#
# (Dette program udskriver et dansk flag, ved at
# sløjfe gennem rækker og kolonner i flaget.)
#

# Constants
FLAG_ROWS = 6
FLAG_COLS = 12

# Registers:
# - row in $t0
# - col in $t1
# - row offset in $t2
# - row+col offset in $t3
main:
main__row_loop_init:                    # for (int row = 0; row < FLAG_ROWS; row++) {
	li	$t0, 0                  # row = 0

	main__row_loop_body:            # while (row < FLAG_ROWS)
	bge	$t0, FLAG_ROWS, main__row_loop_end

	main__col_loop_init:            # for (int col = 0; col < FLAG_COLS; col++) {
	li	$t1, 0                  # col = 0;

	main__col_loop_body:            # while (col < FLAG_COLS)
	bge	$t1, FLAG_COLS, main__col_loop_end

					# convert [row][col] to byte offset
	mul	$t2, $t0, FLAG_COLS     # 1) row offset = rowNumber * NUM_COLUMNS
	add	$t3, $t2, $t1           # 2) row+col offset = rowOffset + colNumber
					# 3) byte offset = row+col offset * sizeof(char)
					#    (Step 3 is skipped since sizeof(char) == 1)
	la	$t4, flag               # 4) Add the base address of the flag array to the byte offset.
	add	$t5, $t3, $t4           #    This produces the complete memory address of the flag element.

	lb	$a0, ($t5)              # 5) Load the byte at the byte offset into $a0

	li	$v0, 11                 # printf("%c", flag[row][col])
	syscall

	main__col_loop_iter:
	addi	$t1, $t1, 1             # col++
	j	main__col_loop_body

	main__col_loop_end:
	main__row_loop_iter:
	li	$a0, '\n'               # printf("%c", '\n')
	li	$v0, 11
	syscall
	addi	$t0, $t0, 1             # row++
	j	main__row_loop_body

	main__row_loop_end:
					# End of the program.
	li	$v0, 0                  # return 0
	jr	$ra

.data
# This label inside the data region refers to the bytes of the flag.
# Note that even thought the bytes are listed on separate lines,
# they are actually stored as a single contiguous chunk or 'string' in memory.
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
