// process creation and synchronisation

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();   // create process

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process\n");
        printf("PID: %d\n", getpid());
    }
    else {
        // Parent process
        wait(NULL);  // wait for child
        printf("Parent Process\n");
        printf("PID: %d\n", getpid());
    }

    return 0;
}