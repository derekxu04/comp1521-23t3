#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);

    printf("%d, 0x%x, 0%o\n", n, n, n);

    return 0;
}
