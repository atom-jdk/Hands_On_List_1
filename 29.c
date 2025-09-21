/*
============================================================================
Name        : 29.c
Author      : Abhash Tiwari
Description : Get and set scheduling policy using sched_getscheduler() and sched_setscheduler().
Date        : 6th Sep, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main() {
    pid_t pid = getpid();

    int policy = sched_getscheduler(pid);
    

    printf("Current scheduling policy of PID %d: ", pid);
    if (policy == SCHED_OTHER) printf("default time sharing policy\n");
    else if (policy == SCHED_FIFO) printf("FIFO policy\n");
    else if (policy == SCHED_RR) printf("RR policy\n");
    else printf("Unknown\n");

    // Set new scheduling policy (SCHED_RR) with priority 10
    struct sched_param param;
    param.sched_priority = 10;
     printf("Scheduling policy changed to RR with priority 10\n");
    

    // Get updated scheduling policy
    policy = sched_getscheduler(pid);
    printf("Updated scheduling policy of PID %d: ", pid);
    if (policy == SCHED_OTHER) printf("default time sharing policy\n");
    else if (policy == SCHED_FIFO) printf("FIFO policy\n");
    else if (policy == SCHED_RR) printf("RR policy\n");
    else printf("Unknown\n");

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/29$ vim 29.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/29$ gcc 29.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/29$ ./a.out
Current scheduling policy of PID 1210: SCHED_OTHER
sched_setscheduler: Operation not permitted
Updated scheduling policy of PID 1210: SCHED_OTHER
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/29$
============================================================================
*/


