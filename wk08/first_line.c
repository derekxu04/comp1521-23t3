// Write a C program, first_line.c, which is given one command-line argument -
// the name of a file - and which prints the first line of that file to stdout.
// If given an incorrect number of arguments, or if there was an error opening
// the file, it should print a suitable error message.
//
// A line may be of any size.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror(argv[1]);
        exit(1);
    }

    /*
    char line[256];
    fgets(line, 256, fp);
    printf("%s\n", line);
    */

    int c = fgetc(fp);
    while (c != EOF && c != '\n') {
        printf("%c", c);

        c = fgetc(fp);
    }

    fclose(fp);

    return 0;
}
