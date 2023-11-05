/**
 * Write a C program, print_diary.c,
 * which prints the contents of the file $HOME/.diary to stdout.
 * echo "hello world" > "$HOME/.diary"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char const *basename = ".diary";

int main(int argc, char *argv[]) {
    // TODO: construct diary_pathname

    // Attempt to open up created path
    FILE *stream = fopen(diary_pathname, "r"); 
    if (stream == NULL) {
        perror(diary_pathname);
        return 1;
    }

    int letter;
    while ((letter = fgetc(stream)) != EOF) {
        // Print the file 1 letter (byte) at a time
        fputc(letter, stdout);
    }
    
    // Clean up once we're done.
    fclose(stream);

    return 0;
}
