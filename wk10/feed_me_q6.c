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

}

int main(void) {


    // TODO: create a thread
    


    // TODO: print out lines
    


    // TODO: cancel the thread upon completion
    return 0;
}