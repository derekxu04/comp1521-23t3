#include <assert.h>
#include <stdio.h>

// most machines have 32 bit integers
// C standard states this can be anything >= 16 bits
// We will assume that unsigned int has 32 bits here
typedef unsigned int Word;

// Helper function
void print_word_binary(char *string, Word value);

Word reverse_bits(Word value) {
    Word reversed = 0;

    for (int i = 0; i < 32; i++) {
        // Get the ith bit of value from the right
        Word mask = 1;
        mask <<= i;

        Word is_one = mask & value;

        // Set the ith bit of reversed from the left
        if (is_one != 0) {
            mask = 1;
            mask <<= (31 - i);

            // Alternative:
            // mask = 0x8000
            // mask >>= i;

            reversed |= mask;
        }

        print_word_binary("reversed", reversed);
    }

    return reversed;
}

int main(void) {
    // assert(reverse_bits(0xFFFFFFFF) == 0xFFFFFFFF);
    // assert(reverse_bits(0x00000000) == 0x00000000);
    // assert(reverse_bits(0x1) == 0x80000000);
    // assert(reverse_bits(0x2) == 0x40000000);
    assert(reverse_bits(0x01234567) == 0xE6A2C480);
    printf("All tests passed!\n");
    return 0;
}

////////////// HELPER FUNCTIONS //////////////
void print_word_binary(char *string, Word value) {
    printf("%s:\t", string);
    for (int i = 31; i >= 0; i--) {
        putchar(((value & ((Word)0x1 << i)) >> i) + 48);
    }
    putchar('\n');
}


// printf("%d", 10) -> decimal         10
// printf("0x%x", 10) -> hexadecimal   0xA
// printf("0%o", 10) -> octal          012