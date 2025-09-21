/*
============================================================================
Name        : 14.c
Author      : Abhash Tiwari
Description : Identify file type using lstat().
Date        : 6th Sep, 2025
============================================================================
*/

#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat st;

    // Use lstat to get file info
    if (lstat("file1.txt", &st) < 0) {
        perror("lstat");
        return 1;
    }

    printf("File type of 'file1.txt': ");

    if (S_ISREG(st.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(st.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISCHR(st.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(st.st_mode))
        printf("Block Device\n");
    else if (S_ISFIFO(st.st_mode))
        printf("FIFO (Pipe)\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Socket\n");
    else
        printf("Unknown\n");

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 14
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/14$ vim 14.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/14$ gcc 14.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/14$ ./a.out
File type of 'file1.txt': Regular File

============================================================================
*/

