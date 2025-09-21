/*
============================================================================
Name        : 25.c
Author      : Abhash Tiwari
Description : Wait for a particular child using waitpid() (parent waits only one child).
Date        : 6th Sep, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1 = fork();

    if (pid1 < 0) {
        perror("fork");
        return 1;
    } else if (pid1 == 0) {
        // First child
        printf("First child started. PID = %d\n", getpid());
        sleep(3);
        printf("First child exiting. PID = %d\n", getpid());
        exit(1);
    }

    pid_t pid2 = fork();

    if (pid2 < 0) {
        perror("fork");
        return 1;
    } else if (pid2 == 0) {
        // Second child
        printf("Second child started. PID = %d\n", getpid());
        sleep(5);
        printf("Second child exiting. PID = %d\n", getpid());
        exit(2);
    }

    pid_t pid3 = fork();

    if (pid3 < 0) {
        perror("fork");
        return 1;
    } else if (pid3 == 0) {
        // Third child
        printf("Third child started. PID = %d\n", getpid());
        sleep(4);
        printf("Third child exiting. PID = %d\n", getpid());
        exit(3);
    }

    
    int status;
    printf("Parent waiting for second child: PID = %d\n", pid2);
    waitpid(pid2, &status, 0);  
    if (WIFEXITED(status))
        printf("Second child exited with status %d\n", WEXITSTATUS(status));

    printf("Parent finished without waiting for first and third child.\n");

    return 0;
}

/*
============================================================================
Sample Output (Terminal Commands Included):
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ mkdir 25
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 25
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/25$ vim 25.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/25$ gcc 25.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/25$ ./a.out
First child started. PID = 1085
Second child started. PID = 1086
Third child started. PID = 1087
Parent waiting for second child: PID = 1086
Second child exiting. PID = 1086
Second child exited with status 2
First child exiting. PID = 1085
Third child exiting. PID = 1087
Parent finished without waiting for first and third child.

============================================================================
*/
