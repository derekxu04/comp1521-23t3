#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file> [<byte position> ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    int offset = 100;
    if (fseek(file, offset, SEEK_SET) != 0) {
        perror("fseek");
        return 1;
    }
    int byte = fgetc(file);
    if (isprint(byte)) {
        printf("%d - 0x%02X - '%c'\n", byte, byte, byte);
    } else {
        printf("%d - 0x%02X\n", byte, byte);
    }

    fclose(file);

    return 0;
}