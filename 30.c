/*
============================================================================
Name        : 30.c
Author      : Abhash Tiwari
Description : Simple program to run a script at a specific HH:MM time and exit.
Date        : 21st Sep, 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <HH> <MM>\n", argv[0]);
        return 1;
    }

    int target_hour = atoi(argv[1]);
    int target_min = atoi(argv[2]);

    printf("Waiting to run the script at %02d:%02d...\n", target_hour, target_min);

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == target_hour && t->tm_min == target_min) {
            printf("Running script now!\n");
            system("/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/30/myscript.sh");
  
            break; // Exit after running once
        }

        sleep(10); // check every 10 seconds
    }

    printf("Script executed. Exiting.\n");
    return 0;
}


/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/30$ vim 30.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/30$ gcc.c
gcc.c: command not found
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/30$ gcc 30.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/30$ ./a.out
Usage: ./a.out <HH> <MM>
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/30$ ./a.out 21 14
Daemon started with PID 1245
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/30$
============================================================================
*/

