#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pipe_ends[2];
    char* pipe_input = "Hello!";
    char pipe_output[50];
    pipe(pipe_ends);

    int fork_res = fork();

    if (fork_res < 0)
    {
        printf("Fork failed");
        exit(1);
    }
    else if (fork_res == 0)
    {
        close(pipe_ends[0]);
        sleep(10);
        write(pipe_ends[1], pipe_input, strlen(pipe_input) + 1);
        printf("Child done\n");
    }
    else
    {
        close(pipe_ends[1]);

        int nbytes = read(pipe_ends[0], pipe_output, sizeof(pipe_output));
        printf("String: %s\nNbytes: %d\n", pipe_output, nbytes);
    }
    return 0;
}