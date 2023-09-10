// clang -E q8.c : preprocessing
// clang -S q8.c : assembly code, architecture dependent (q8.s)
// clang -c q8.c : machine code (q8.o)
// clang q8.c    : executable

#include <stdio.h>
#define N 10

int main(void) {
    char str[N] = { 'H', 'i', '\0' };
    printf("%s\n", str);
    return 0;
}
