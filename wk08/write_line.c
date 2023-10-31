// Write a C program, write_line.c, which is given one command-line argument,
// the name of a file, and which reads a line from stdin, and writes it to the
// specified file; if the file exists, it should be overwritten (rather than appended).
//


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {\
    if (argc <= 1) {
        fprintf(stderr, "Please provide a filename\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "a");

    if (fp == NULL) {
        perror(argv[1]);
        exit(1);
    }

    int c = getchar();
    while (c != '\n') {
        // fprintf(fp, "%c", c);
        fputc(c, fp);

        c = getchar();
    }

    fputc('\n', fp);

    fclose(fp);
    return 0;
}

// What change would we make if we wanted to append to a file rather than
// overwrite it?