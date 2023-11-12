/**
 * Write a program, now.c which prints out the current date and time by 
 * calling other programs.
*/

#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>

#define DATE_PATH "/usr/bin/date"

// int posix_spawn(pid_t *restrict pid, const char *restrict path,
//                        const posix_spawn_file_actions_t *restrict file_actions,
//                        const posix_spawnattr_t *restrict attrp,
//                        char *const argv[restrict],
//                        char *const envp[restrict]);

int main(void) {
    // call posix_spawn to print date +%d-%m-%Y

    extern char **environ;

    pid_t date_fulldate_pid;

    char *spawn_fulldate_argv[] = {DATE_PATH, "+%d-%m-%Y", NULL};

       
    //          &date_fulldate_pid: pointer to an uninitialised pid_t
    //                              DATE_PATH: path to the program for the new process to run
    //                                         NULL: file_actions, not relevant for this course
    //                                               NULL: spawn attributes, also not relevant
    //                                                     spawn_fulldate_argv: command line arguments for the new process
    //                                                                          environ: pass a pointer to our environment variables
    //                                                                          for the new process to copy
    posix_spawn(&date_fulldate_pid, DATE_PATH, NULL, NULL, spawn_fulldate_argv, environ);

    int exit_status;
    //          date_fulldate_pid: PID of the child we are waiting for
    //                             &exit_status: stores the exit status of the child - don't worry too much her
    //                                           0: options - can be 0 for this course
    if (waitpid(date_fulldate_pid, &exit_status, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    // call posix_spawn to print date +%T

    pid_t date_time_pid;
    char *spawn_time_argv[] = {DATE_PATH, "+%T", NULL};

    posix_spawn(&date_time_pid, DATE_PATH, NULL, NULL, spawn_time_argv, environ);
    if (waitpid(date_time_pid, &exit_status, 0) == -1) {
        perror("waitpid");
        return 1;
    }


    printf("the date and time are above!\n");


    return 0;
}
