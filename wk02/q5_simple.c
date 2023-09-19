// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.
// Simplified C version.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x <= SQUARE_MAX) goto square_small_enough;

    printf("square too big for 32 bits\n");

    goto epilogue;

square_small_enough:
    y = x * x;
    printf("%d\n", y);

epilogue:

    return 0;
}
