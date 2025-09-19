/*
============================================================================
Name : 1.c
Author : Abhash Tiwari
Description : Write a C, Ansi-style program to create 
              a. Soft link 
              b. Hard link 
              c. FIFO
Date : 6th Sep, 2025
============================================================================
*/

#include <unistd.h>
#include <sys/stat.h>

int main() {
    symlink("f1.txt", "softlink_f1");   // create soft link
    link("f1.txt", "hardlink_f1");      // create hard link
    mkfifo("myfifo", 0666);             // create FIFO
    return 0;
}

/*
============================================================================
Sample Output :
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ mkdir 1
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 1
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/1$ vim 1.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/1$ touch f1.txt
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/1$ gcc 1.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/1$ ./a.out
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/1$ ls -l
total 20
-rwxrwxrwx 1 abhsh abhsh  1396 Sep  6 13:10 1.c
-rwxrwxrwx 1 abhsh abhsh 16024 Sep  6 13:10 a.out
-rwxrwxrwx 2 abhsh abhsh     0 Sep  6 13:10 f1.txt
-rwxrwxrwx 2 abhsh abhsh     0 Sep  6 13:10 hardlink_f1
lrwxrwxrwx 1 abhsh abhsh     6 Sep  6 13:11 softlink_f1 -> f1.txt

# Equivalent Linux commands:
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/1$ ln -s f1.txt softlink_f1
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/1$ ln f1.txt hardlink_f1
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/1$ mkfifo myfifo

----------------------------------------------------------------------------

============================================================================
*/


