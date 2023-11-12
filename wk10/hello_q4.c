/**
 * Write a C program that creates a thread that infinitely prints some 
 * message provided by main (eg. "Hello\n"), while the main (default) 
 * thread infinitely prints a different message (eg. "there!\n").
*/

#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

void *thread_run(void *data) {
    char *string = data;

    while (true) {
        printf("%s\n", string);
    }

    return NULL;
}

int main(void) {
    // TODO: create a thread
    
    // TODO: print the main message

    return 0;
}
