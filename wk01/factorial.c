#include <stdio.h>

int factorial(int n);

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}

int factorial(int n) {
    // int fac = 1;
    // for (int i = 1; i <= n; i++) {
    //     fac *= i;
    // }
    // return fac;

    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
