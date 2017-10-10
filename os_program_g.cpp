#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main ( int argc, char *argv[] )
{
    int i, pid, process;
    process = atoi(argv[1]) - 1;

    for(i = 0; i < process; i++) {
        pid = fork();
        if(pid < 0) {
            printf("Error");
            exit(1);
        } else if (pid == 0) {
            printf("Child (%d): %d\n", i + 1, getpid());
            exit(0);
        } else  {
            wait(NULL);
        }
    }

}