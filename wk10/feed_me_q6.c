/**
 * Write a C program that creates a thread which infinitely prints 
 * the message "feed me input!\n" once per second (sleep), while 
 * the main (default) thread continuously reads in lines of input, 
 * and prints those lines back out to stdout with the prefix: 
 * "you entered: ".
*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *data) {
    // todo: complete this function

    while (true) {
        printf("feed me input!\n");
        sleep(1);
    }

    return NULL;
}

int main(void) {
    // TODO: create a thread
    pthread_t thread;
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );

    // TODO: print out lines
    char line[1024];
    while (fgets(line, 1024, stdin) != NULL) {
        printf("you entered: %s", line);
    }
    
    // TODO: cancel the thread upon completion
    pthread_cancel(thread);

    return 0;
}