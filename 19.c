/*
============================================================================
Name        : 19.c
Author      : Abhash Tiwari
Description : Print PID and measure time using CPU TSC (RDTSC).
Date        : 6th Sep, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc(){
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    

    uint64_t start = rdtsc();
    pid_t pid = getpid();
    uint64_t end = rdtsc();

    printf("Process ID: %d\n", pid);
    printf("CPU cycles elapsed: %lu\n", end - start);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 19
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/19$ vim 19.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/19$ gcc 19.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/19$ ./a.out
Process ID: 906
CPU cycles elapsed: 1584479
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/19$
============================================================================
*/

