/*
============================================================================
Name        : 11.a.c
Author      : Abhash Tiwari
Description : Duplicate file descriptor fd1 to stderr and inspect /proc/<PID>/fd
Date        : 20th Sep, 2025
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd1;

   
    fd1 = open("a.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

  
    close(2);

   
    dup(fd1);

    printf("PID = %d\n", getpid());


    getchar();

    return 0;
}

/*
============================================================================
Sample Terminal Session:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11$ vim 11.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11$ gcc 11.c -o a.out
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11$ ./a.out &
[1] 2580
PID = 2580
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11$ cd /proc/2580/fd
abhsh@Abhash12:/proc/2580/fd$ ls -l
lrwx------ 1 abhsh abhsh 64 Sep 20 18:37 0 -> /dev/pts/0
lrwx------ 1 abhsh abhsh 64 Sep 20 18:37 1 -> /dev/pts/0
l-wx------ 1 abhsh abhsh 64 Sep 20 18:37 2 -> /mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11/a.txt
l-wx------ 1 abhsh abhsh 64 Sep 20 18:37 3 -> /mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11/a.txt
abhsh@Abhash12:/proc/2580/fd$

============================================================================
*/
