/*
============================================================================
Name        : 11.c
Author      : Abhash Tiwari
Description : Duplicate file descriptor using fcntl(F_DUPFD).
Date        : 20th Sep, 2025
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd1, fd_dup;

    // Open a file for writing
    fd1 = open("fcntl_output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);


    // Duplicate fd1 using fcntl, minimum fd number = 5
    fd_dup = fcntl(fd1, F_DUPFD, 5);

    // Write using original fd
    write(fd1, "Line 1 using fd1\n", 17);

    // Write using duplicated fd
    write(fd_dup, "Line 2 using fd_dup\n", 20);

    close(fd1);
    close(fd_dup);

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

$ gcc fcntl_dup.c -o fcntl_dup
$ ./fcntl_dup
$ cat fcntl_output.txt
Line 1 using fd1
Line 2 using fd_dup
============================================================================
*/

