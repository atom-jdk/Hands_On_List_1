/*
============================================================================
Name        : 22.c
Author      : Abhash Tiwari
Description : Parent and child write to the same file using fork().
Date        : 6th Sep, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("shared.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        write(fd, "Child writing...\n", strlen("Child writing...\n"));
    } else {
        // Parent process
        write(fd, "Parent writing...\n", strlen("Parent writing...\n"));
    }

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 22
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/22$ gcc 22.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/22$ ./a.out
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/22$ cat shared.txt
Parent writing...
Child writing...

# Note: Order may vary due to scheduling

============================================================================
*/


