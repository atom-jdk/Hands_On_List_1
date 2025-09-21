/*
============================================================================
Name        : 12.c
Author      : Abhash Tiwari
Description : Get the opening mode of a file using fcntl() (simple version).
Date        : 6th Sep, 2025
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("mode.txt", O_RDWR | O_CREAT, 0644);
    int flags = fcntl(fd, F_GETFL);

    if ((flags & O_ACCMODE) == O_RDONLY) 
        printf("Read Only\n");
    else if ((flags & O_ACCMODE) == O_WRONLY) 
        printf("Write Only\n");
    else 
        printf("Read & Write\n");

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 12
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/12$ vim 12.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/12$ gcc 12.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/12$ ./a.out
Read & Write

============================================================================
*/

