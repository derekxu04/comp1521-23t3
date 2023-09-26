# A simple program that will read 10 numbers into an array

# Constant for the size of the array
# This is treated like a literal (i.e. you load it with `li`, not `la/lb/lw`) but is more 
# readable than a magic number
N_SIZE = 10

        .text

main:
        # Registers:
        # - $t0: int i, the loop counter (i.e. the index of the array)
        # - $t1: The number of bytes in the array we need to offset
        # - $t2: The base address of the array we are reading into
        # - $t3: The memory address we will store a 4-byte integer into

scan_loop_init:
        li      $t0, 0                  # i = 0

scan_loop_cond:
        bge     $t0, N_SIZE, scan_loop_end      # while (i < N_SIZE) {

        li      $v0, 5                  # scanf("%d", &numbers[i]);
        syscall                         # Stores the result in $v0

                                        # calculate &numbers[i]
                                        # Address = base + offset*sizeof(element)
        mul     $t1, $t0, 4             # 1) Find the number of bytes we need to offset inside the array
                                        #    Since this is a 4-byte integer, we need to multiply by 4.
        la      $t2, numbers            # 2) Find the base address of the array
        add     $t3, $t1, $t2           # 3) Add the offset to the base address
        sw      $v0, ($t3)              # 4) Store entered number in array at the calculated address

                                        # Jump back to the loop condition
        addi    $t0, $t0, 1             # i++;
        j       scan_loop_cond          # }

scan_loop_end:
                                        # End of scan_loop

epilogue:
        jr      $ra                     # return

        .data

numbers:                                        # The array of numbers, initialised to 0
        .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0      # int numbers[10] = {0};