/*
============================================================================
Name        : 27.c
Author      : Abhash Tiwari
Description : Execute 'ls -Rl' using different exec* variants.
Date        : 6th Sep, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    printf("Parent PID = %d: Executing 'ls -Rl'\n", getpid());

    // Using execl
    printf("\n--- Using execl ---\n");
    if (fork() == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl");  // If exec fails
        exit(1);
    }
    wait(NULL);

    // Using execlp
    printf("\n--- Using execlp ---\n");
    if (fork() == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp");
        exit(1);
    }
    wait(NULL);

    // Using execle
    printf("\n--- Using execle ---\n");
       if (fork() == 0) {
        char *envp[] = {"PATH=/bin", NULL};   // custom environment
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
        perror("execle");
        exit(1);
    }
    wait(NULL);

    // Using execv
    printf("\n--- Using execv ---\n");
    if (fork() == 0) {
        char *args[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", args);
        perror("execv");
        exit(1);
    }
    wait(NULL);

    // Using execvp
    printf("\n--- Using execvp ---\n");
    if (fork() == 0) {
        char *args[] = {"ls", "-Rl", NULL};
        execvp("ls", args);
        perror("execvp");
        exit(1);
    }
    wait(NULL);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
Parent PID = 1125: Executing 'ls -Rl'

--- Using execl ---
.:
total 24
-rwxrwxrwx 1 abhsh abhsh  1816 Sep  6 15:10 27.c
-rwxrwxrwx 1 abhsh abhsh 16432 Sep  6 15:10 a.out

--- Using execlp ---
.:
total 24
-rwxrwxrwx 1 abhsh abhsh  1816 Sep  6 15:10 27.c
-rwxrwxrwx 1 abhsh abhsh 16432 Sep  6 15:10 a.out

--- Using execv ---
.:
total 24
-rwxrwxrwx 1 abhsh abhsh  1816 Sep  6 15:10 27.c
-rwxrwxrwx 1 abhsh abhsh 16432 Sep  6 15:10 a.out

--- Using execvp ---
.:
total 24
-rwxrwxrwx 1 abhsh abhsh  1816 Sep  6 15:10 27.c
-rwxrwxrwx 1 abhsh abhsh 16432 Sep  6 15:10 a.out
============================================================================
*/

