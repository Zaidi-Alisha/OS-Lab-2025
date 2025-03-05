#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void print_user_id() {
    uid_t uid = getuid();
    printf("User ID (UID): %d\n", uid);
}

int main() {
    pid_t pid = getpid();
    printf("Current Process ID (PID): %d\n", pid);

    pid_t ppid = getppid();
    printf("Parent Process ID (PPID): %d\n", ppid);

    print_user_id();

    return 0;
}//end main
