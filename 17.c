/*
============================================================================
Name        : 17.c
Author      : Abhash Tiwari
Description : Simple ticket reservation using write lock (fcntl).
Date        : 6th Sep, 2025
============================================================================
*/

/*
============================================================================
Name        : ticket_reservation.c
Author      : Abhash Tiwari
Description : Merge initialization & reservation with write lock.
Date        : 20th Sep, 2025
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("tickets.txt", O_CREAT | O_RDWR, 0644);

    // Prepare write lock for the whole file
    struct flock fl = {0};
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;

    // Acquire lock (wait if already locked)
    fcntl(fd, F_SETLKW, &fl);
    printf("Lock acquired. Reserving ticket...\n");
    sleep(10);

    // Read current ticket count
    int tickets = 0;
    ssize_t n = read(fd, &tickets, sizeof(int));
    if (n != sizeof(int)) tickets = 0; 

    // Increment and write back
    tickets++;
    lseek(fd, 0, SEEK_SET);
    write(fd, &tickets, sizeof(int));

    printf("Ticket reserved. Total tickets: %d\n", tickets);

    // Release lock
    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);

    close(fd);
    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------

abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 17
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/17$ gcc 17.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/17$ ./a.out
Lock acquired. Reserving ticket...
Ticket reserved. Total tickets: 1
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/17$ ./a.out
Lock acquired. Reserving ticket...
Ticket reserved. Total tickets: 2
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/17$ gcc 17.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/17$ ./a.out
Lock acquired. Reserving ticket...
Ticket reserved. Total tickets: 3
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/17$ ./a.out
Lock acquired. Reserving ticket...
Ticket reserved. Total tickets: 4
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/17$

============================================================================
*/

