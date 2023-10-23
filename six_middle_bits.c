#include <stdio.h>
#include <stdint.h>

void print_word_binary(char *string, uint32_t value);

/* 
For example:
00000000 00000101 01000000 01110110 

middle six bits are 10 1010
*/

// TODO
uint32_t six_middle_bits(uint32_t u) {
    return u;
}

int main(void) {
    // num = 0x54076
    uint32_t num = 0b00000000000001010100000001110110;

    // We want the middle 0x2A
    uint32_t result = six_middle_bits(num);
    printf("Middle: 0x%X\n", result);

    return 0;
}

////////////// HELPER FUNCTIONS //////////////
void print_word_binary(char *string, uint32_t value) {
    printf("%s\n", string);
    for (int i = 31; i >= 0; i--) {
        putchar(((value & ((uint32_t)0x1 << i)) >> i) + 48);
    }
    putchar('\n');
}