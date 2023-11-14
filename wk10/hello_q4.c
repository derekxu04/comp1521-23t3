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
        printf("%s", string);
    }

    return NULL;
}

int main(void) {
    // TODO: create a thread
    char *string = "Hello\n";

    pthread_t thread;
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        string        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );

    // TODO: print the main message
    while (true) {
        printf("there\n");
    }


    return 0;
}
