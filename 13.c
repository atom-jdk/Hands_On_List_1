/*
============================================================================
Name        : 13.c
Author      : Abhash Tiwari
Description : Wait up to 10 seconds for input from STDIN using select().
Date        : 6th Sep, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set fds;
    struct timeval timeout;
    char input[100];

    FD_ZERO(&fds);               
    FD_SET(STDIN_FILENO, &fds);

    timeout.tv_sec = 10;        
    timeout.tv_usec = 0;

    printf("Type something within 10 seconds:\n");

    int ready = select(1, &fds, NULL, NULL, &timeout);

    if (ready == 0) {
        printf("Time out! No input.\n");
    } else {
        read(STDIN_FILENO, input, sizeof(input));
        printf("You typed: %s", input);
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 13
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/13$ vim 13.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/13$ gcc 13.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/13$ ./a.out
You have 10 seconds to type something:
hii jabalpurr
You typed: hii jabalpur

============================================================================
*/

