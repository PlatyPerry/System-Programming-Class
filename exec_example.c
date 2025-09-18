#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec - Current process PID: %d\n", getpid());
    
    // Execute the 'ls' command with arguments
    char *args[] = {"ls", "-l", "-a", NULL};
    execvp("ls", args);
    
    // This line will only execute if exec fails
    perror("execvp failed");
    return 1;
}
