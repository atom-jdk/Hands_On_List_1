/*
============================================================================
Name        : 11.b.c
Author      : Abhash Tiwari
Description : Duplicate file descriptor fd1 to stderr using dup2 and inspect /proc/<PID>/fd
Date        : 20th Sep, 2025
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd1;

    
    fd1 = open("a.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    
    dup2(fd1, 2);

    
    close(fd1);

    
    printf("PID = %d\n", getpid());

    
    getchar();

    return 0;
}

/*
============================================================================
Sample Terminal Session:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11$ vim 11.b.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11$ gcc 11.b.c -o a.out
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11$ ./a.out &
[1] 2620
PID = 2620
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11$ cd /proc/2620/fd
abhsh@Abhash12:/proc/2620/fd$ ls -l
lrwx------ 1 abhsh abhsh 64 Sep 20 19:10 0 -> /dev/pts/0
lrwx------ 1 abhsh abhsh 64 Sep 20 19:10 1 -> /dev/pts/0
l-wx------ 1 abhsh abhsh 64 Sep 20 19:10 2 -> /mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/11/a.txt

============================================================================
*/

