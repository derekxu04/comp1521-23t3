// Write a C program, chmod_if_public_write.c, which is given 1+ command-line
// arguments which are the pathnames of files or directories.

// If the file or directory is publically-writeable, it should change it to be
// not publically-writeable, leaving other permissions unchanged.

// It also should print a line to stdout as per the example below.

/*******************************************************************************
 $ dcc chmod_if_public_write.c -o chmod_if_public_write
 $ ls -ld file_modes.c file_modes file_sizes.c file_sizes
-rwxr-xrwx 1 z5555555 z5555555 116744 Nov  2 13:00 file_sizes
-rw-r--r-- 1 z5555555 z5555555    604 Nov  2 12:58 file_sizes.c
-rwxr-xr-x 1 z5555555 z5555555 222672 Nov  2 13:00 file_modes
-rw-r--rw- 1 z5555555 z5555555   2934 Nov  2 12:59 file_modes.c
$ ./file_modes file_modes file_modes.c file_sizes file_sizes.c
removing public write from file_sizes
file_sizes.c is not publically writable
file_modes is not publically writable
removing public write from file_modes.c
$ ls -ld file_modes.c file_modes file_sizes.c file_sizes
-rwxr-xr-x 1 z5555555 z5555555 116744 Nov  2 13:00 file_sizes
-rw-r--r-- 1 z5555555 z5555555    604 Nov  2 12:58 file_sizes.c
-rwxr-xr-x 1 z5555555 z5555555 222672 Nov  2 13:00 file_modes
-rw-r--r-- 1 z5555555 z5555555   2934 Nov  2 12:59 file_modes.c
*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_needed(argv[arg]);
    }
    return 0;
}

void chmod_if_needed(char *pathname) {
    struct stat s;
    int output = stat(pathname, &s);
    if (output != 0) {  // 0 is the success code 
        perror(pathname);
        exit(1);
    }
    // At this point in execution, struct stat s should be filled with data.

    mode_t mode = s.st_mode; // Copy the current mode into a new variable.
    
    // Mode is a 32 bit integer, and 
    // the last 9 bits of the mode represent permissions.
    // Ie. 101 000 011 AT THE END is r-x --- -wx
    // S_IWOTH is a hash define for write public flag (can find these hash defines in stat.h)
    // The if statement executes if it has the S_IWOTH flag in mode.
    if (!(mode & S_IWOTH)) { 
        printf("%s is not publically writable\n", pathname);
        return;
    }
    // EXAMPLE, only considering last 9 permission bits.
    // SI_IWOTH = 0b000000010
    // mode =     0b010101010 (This is currently publicly writeable)
    // S_IWOTH & mode = 0b000000010 (THIS IS NOT ZERO)
    
    // However, if mode = 0b010101000 (This is not public writeable)
    // S_IWOTH & mode = 0 

    printf("removing public write from %s\n", pathname);

    mode_t new_mode = mode & ~S_IWOTH; // Removing the write public flag
    // EXAMPLE
    // SI_IWOTH = 0b0000000010
    // mode =     0b0010101010 (This is currently public writeable)
    // ~S_IWOTH = 0b1111111101
    // mode & ~S_IWOTH = 0b0010101000 (REMOVED PUBLIC WRITE FLAG.) 
		
    if (chmod(pathname, new_mode) != 0) { // check if chmod successful
        perror(pathname);
        exit(1);
    }
}
