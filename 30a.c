#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <HH> <MM>\n", argv[0]);
        return 1;
    }

    int target_hour = atoi(argv[1]);
    int target_min = atoi(argv[2]);

    pid_t pid = fork();
    if (pid < 0) exit(1);
    if (pid > 0) {
        printf("Daemon started with PID %d\n", pid);
        exit(0);
    }

    if (setsid() < 0) exit(1);

    umask(0);
    chdir("/");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == target_hour && t->tm_min == target_min) {
            system("/mnt/c/Users/abhas/OneDrive/Desktop/Hand_On_List/30/myscript.sh");
            break;
        }

        sleep(30);
    }

    return 0;
}
