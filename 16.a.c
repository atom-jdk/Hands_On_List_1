/*
============================================================================
Name        : 16.c
Author      : Abhash Tiwari
Description : File locking (advisory) using fcntl().
Date        : 6th Sep, 2025
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("mand.txt", O_CREAT | O_RDWR, 0640); 
    

    struct flock lock;
    lock.l_type = F_WRLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;         

    printf("Trying to acquire write lock...\n");
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        printf("Cannot acquire write lock, another process holds it.\n");
    } else {
        printf("Write lock acquired!\n");
    }

    printf("Press Enter to release lock...");
    getchar();  // wait for user input

    // Unlock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Lock released.\n");

    close(fd);
    return 0;
}


/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/16$ touch mand.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/16$ chmod 640 mand.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/16$ chmod g+s mand.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/16$ gcc 16.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/16$ ./a.out
Trying to acquire write lock...
Write lock acquired!
Press Enter to release lock...
Lock released.
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/16$

============================================================================
*/

