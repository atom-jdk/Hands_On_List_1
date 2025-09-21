/*
============================================================================
Name        : 10.c
Author      : Abhash Tiwari
Description : Create a hole in a file using lseek().
Date        : 6th Sep, 2025
============================================================================
*/

#include <unistd.h>   // for write(), lseek(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

int main() {
    int fd;
    
    // Open file for writing (create if it doesn't exist)
    fd = open("hole.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write some initial data
    write(fd, "Hello", 5);

    // Move file pointer 10 bytes ahead (creates a hole)
    lseek(fd, 10, SEEK_CUR);

    // Write more data after the hole
    write(fd, "World", 5);

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 10
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/10$ vim 10.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/10$ gcc 10.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/10$ ./a.out
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/10$ ls -l hole.txt
-rwxrwxrwx 1 abhsh abhsh 20 Sep  6 13:52 hole.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/10$ od -c hole.txt
0000000   H   e   l   l   o   w    o   r   l   d   \0  \0  \0  \0  \0  \0  \0  \0  \0  \0   W
0000020   o   r   l   d   h   e    l   l   o
0000030
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/10$
============================================================================
*/

