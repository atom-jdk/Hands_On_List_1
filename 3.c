/*
============================================================================
Name : 3.c
Author : Abhash Tiwari
Description : Write a C, Ansi-style program to create a file using creat()
              system call and print its file descriptor.
Date: 6th Sep, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // create file with rw-r--r-- permissions
    fd = creat("myfile.txt", 0644);

    if (fd < 0) {
        perror("creat");
        return 1;
    }

    printf("File created successfully. File Descriptor: %d\n", fd);

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/2$ cd ..
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ mkdir 3
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 3
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/3$ vim 3.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/3$ gcc 3.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/3$ ./a.out
File created successfully. File Descriptor: 3
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/3$ ls -l
total 20
-rwxrwxrwx 1 abhsh abhsh  1212 Sep  6 13:22 3.c
-rwxrwxrwx 1 abhsh abhsh 16088 Sep  6 13:22 a.out
-rwxrwxrwx 1 abhsh abhsh     0 Sep  6 13:23 myfile.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/3$
============================================================================
*/

