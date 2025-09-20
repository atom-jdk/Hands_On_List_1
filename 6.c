/*
============================================================================
Name        : 6.c
Author      : Abhash Tiwari
Description : Echo program using read() and write() system calls only.
              Keeps echoing multiple lines until Ctrl+D (EOF) is pressed.
Date        : 6th Sep, 2025
============================================================================
*/

#include <unistd.h>  // for read() and write()

int main() {
    char c;

    // Keep reading characters until EOF (Ctrl+D)
    while (read(0, &c, 1) > 0) {
        write(1, &c, 1);  // write each character immediately
    }

    return 0;
}

/*
============================================================================
Sample Output:
----------------------------------------------------------------------------
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/5$ cd ..
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List$ cd 6
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/6$ vim 6.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/6$ gcc 6.c
abhsh@Abhash12:/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/6$ ./a.out
hello jabalpur
hello jabalpur
hello 2nd time
hello 2nd time

============================================================================
*/

