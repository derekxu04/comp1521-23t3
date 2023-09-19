// Simple factorial calculator  - without error checking
// Simplified C version.

#include <stdio.h>

int main(void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;

loop_init:

    int i = 1;

loop_cond:

    if (i > n) goto loop_end;

loop_body:

    fac = fac * i;

    i++;
    goto loop_cond;

loop_end:

    printf("n! = %d\n", fac);
    return 0;
}
