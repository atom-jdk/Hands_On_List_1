/*
============================================================================
Name        : 9.c
Author      : Abhash Tiwari
Description : Print file metadata using stat() system call.
Date        : 6th Sep, 2025
============================================================================
*/

#include <sys/stat.h>   // for stat()
#include <unistd.h>     // for close()
#include <stdio.h>      // for printf(), perror()
#include <time.h>       // for ctime()

int main() {
    struct stat fileStat;

    // Get file metadata
    if (stat("f1.txt", &fileStat) < 0) {
        perror("stat");
        return 1;
    }

    // Print file metadata
    printf("File: f1.txt\n");
    printf("File Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Number of Links: %ld\n", (long)fileStat.st_nlink);
    printf("File inode: %ld\n", (long)fileStat.st_ino);
    printf("File Permissions: ");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    printf("Last Access: %s", ctime(&fileStat.st_atime));
    printf("Last Modification: %s", ctime(&fileStat.st_mtime));
    printf("Last Status Change: %s", ctime(&fileStat.st_ctime));

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ mkdir 9
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 9
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/9$ vim 9.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/9$ gcc 9.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/9$ ./a.out
stat: No such file or directory
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/9$ touch f1.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/9$ echo "hi this is again f1 for 9th " > f1.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/9$ gcc 9.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/9$ ./a.out
File: f1.txt
File Size: 29 bytes
Number of Links: 1
File inode: 4222124652209298
File Permissions: -rwxrwxrwx
Last Access: Sat Sep  6 13:50:50 2025
Last Modification: Sat Sep  6 13:50:50 2025
Last Status Change: Sat Sep  6 13:50:50 2025
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/9$
============================================================================
*/

