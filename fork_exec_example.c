#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process - execute a command
        printf("Child process executing 'ls -l':\n");
        execlp("ls", "ls", "-l", NULL);
        
        // If exec fails
        perror("execlp failed");
        return 1;
    } else {
        // Parent process - wait for child to complete
        printf("Parent process waiting for child (PID: %d)...\n", pid);
        wait(NULL);
        printf("Child process completed.\n");
    }
    
    return 0;
}
