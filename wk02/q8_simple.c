// Prints a right-angled triangle of asterisks, 10 rows high.
// Simplified C version.

#include <stdio.h>

int main(void) {
    int i = 1;

line_loop_start:
    if (i > 10) goto line_loop_end;

    int j = 0;

character_loop_start:
    if (j >= i) goto character_loop_end;

    printf("%c", '*');

    j++;
    goto character_loop_start;

character_loop_end:

    printf("%c", '\n');

    i++;
    goto line_loop_start;

line_loop_end:
    // This is the end of the loop.

    return 0;
}
