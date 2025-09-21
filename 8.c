/*
============================================================================
Name        : 8.c
Author      : Abhash Tiwari
Description : Read a file line by line using system calls only (read-only).
Date        : 6th Sep, 2025
============================================================================
*/

#include <unistd.h>   // for read(), write(), close()
#include <fcntl.h>    // for open()
#include <stdio.h>    // for perror()

#define BUF_SIZE 1024   // read in chunks

int main() {
    int fd;
    char buffer[BUF_SIZE];
    ssize_t n;
    int i;

    
    fd = open("f1.txt", O_RDONLY);
    if (fd < 0) {
        perror("open f1.txt");
        return 1;
    }

   
    while ((n = read(fd, buffer, BUF_SIZE)) > 0) {
        for (i = 0; i < n; i++) {
            write(1, &buffer[i], 1);  
            if (buffer[i] == '\n') {
               // line khtm..
            }
        }
    }

    if (n < 0) {
        perror("read");
    }

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ mkdir 8
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 8
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/8$ vim 8.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/8$ echo "hi this is f1 file" > f1.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/8$ echo "second line of file" >> f1.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/8$ gcc 8.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/8$ ./a.out
hi this is f1 file
second line of file

============================================================================
*/
