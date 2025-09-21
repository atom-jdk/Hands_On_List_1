/*
============================================================================
Name        : 16_read.c
Author      : Abhash Tiwari
Description : File locking (read lock) using fcntl() (mandatory possible).
Date        : 6th Sep, 2025
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("mand.txt", O_CREAT | O_RDWR, 0640); // group execute off for mandatory lock
    
    struct flock lock;
    lock.l_type = F_RDLCK;   // read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;          // whole file

    printf("Trying to acquire read lock...\n");
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        printf("Cannot acquire read lock, another process holds a conflicting lock.\n");
    } else {
        printf("Read lock acquired!\n");
    }

    printf("Press Enter to release lock...");
    getchar();  

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
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/16$ gcc 16.b.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/16$ ./a.out
Trying to acquire read lock...
Read lock acquired!
Press Enter to release lock...
Lock released.
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/16$
============================================================================
*/
