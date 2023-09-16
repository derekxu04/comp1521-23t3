// Simple factorial calculator  - without error checking
// Simplified C version.

#include <stdio.h>

int main(void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;
    int i = 1;

fac_loop:
    // Loop exit condition, the inverse of 'while(i <= n)'
    if (i > n) goto epilogue;

    // Loop body
    fac *= i;

    // Increment the loop counter and loop back to the top.
    i++;
    goto fac_loop;

epilogue:

    printf("n! = %d\n", fac);
    return 0;
}
