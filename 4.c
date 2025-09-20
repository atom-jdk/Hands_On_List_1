/*
============================================================================
Name : 4.c
Author : Abhash Tiwari
Description : Write a C, Ansi-style program to open an existing file in
              read-write mode. Also try to use O_EXCL flag.
Date: 6th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // Try to open existing file "myfile.txt" in read-write mode
    fd = open("myfile.txt", O_RDWR);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("File opened successfully in read-write mode. FD: %d\n", fd);
    close(fd);

    // Now try opening with O_EXCL along with O_CREAT
    fd = open("myfile.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd < 0) {
        perror("open with O_EXCL");
    } else {
        printf("File opened with O_EXCL. FD: %d\n", fd);
        close(fd);
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ mkdir 4
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 4
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/4$ vim 4.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/4$ gcc 4.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/4$ touch myfile.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/4$ ./a.out
File opened successfully in read-write mode. FD: 3
open with O_EXCL: File exists
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/4$ ls -l
total 20
-rwxrwxrwx 1 abhsh abhsh  1350 Sep  6 13:45 4.c
-rwxrwxrwx 1 abhsh abhsh 16088 Sep  6 13:45 a.out
-rw-r--r-- 1 abhsh abhsh     0 Sep  6 13:46 myfile.txt

============================================================================
*/

