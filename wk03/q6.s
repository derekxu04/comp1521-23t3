# A simple program that will print 10 number from an array

# Constant for the size of the array
# This is treated like a literal (i.e. you load it with `li`, not `la/lb/lw`) but is more 
# readable than a magic number
NUMBERS_SIZE = 10

        .text

main:
        # Registers:
        # - $t0: int i, the loop counter (i.e. the index of the array)
        # - $t1: The number of bytes in the array we need to offset
        # - $t2: The base address of the array we are reading from
        # - $t3: The memory address we will load a 4-byte integer from

print_loop_init:
        li      $t0, 0                  # i = 0

print_loop_cond:
        bge     $t0, NUMBERS_SIZE, print_loop_end       # while (i < NUMBERS_SIZE) {

                                        # calculate &numbers[i]
                                        # Address = base + offset*sizeof(element)
        mul     $t1, $t0, 4             # 1) Find the number of bytes we need to offset inside the array
                                        #    Since this is a 4-byte integer, we need to multiply by 4.
        la      $t2, numbers            # 2) Find the base address of the array
        add     $t3, $t1, $t2           # 3) Add the offset to the base address
        lw      $a0, ($t3)              # 4) Load the 4-byte integer, numbers[i], into $a0 to print

        li      $v0, 1                  # printf("%d", numbers[i])
        syscall

        li      $a0, '\n'               # printf("%c", '\n');
        li      $v0, 11
        syscall

                                        # Jump back to the loop condition
        addi    $t0, $t0, 1             # i++;
        j       print_loop_cond         # }

print_loop_end:
                                        # End of print_loop

epilogue:
        jr      $ra                     # return

        .data

numbers:
        .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9  # int numbers[N_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
