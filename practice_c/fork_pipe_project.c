#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "its_header.h"

const int EXEC_ARR_LEN = 2;

int main(int argc, char *argv[])
{
    // Initialize pipe
    int pipe_arr[2];
    pipe(pipe_arr);

    int fork_num = fork();

    if(fork_num < 0){
        printf("Fork failed");
        exit(1);
    }
    else if (fork_num == 0){
        printf("Child fork\n");

        // Close unused pipe end
        close(pipe_arr[0]);

        char* exec_arr[3];
        exec_arr[0] = "./foo2";
        exec_arr[1] = malloc(sizeof(char) * 10);
        strcpy(exec_arr[1], int_to_string(pipe_arr[1]));
        exec_arr[2] = NULL;

        execvp(exec_arr[0], exec_arr);
        return 0;
    }
    else{
        wait(NULL);
        printf("Parent fork\n");

        close(pipe_arr[1]);

        char pipe_output[50];
        int nbytes = read(pipe_arr[0], pipe_output, sizeof(pipe_output));

        printf("%s\n", pipe_output);
        close(pipe_arr[0]);

        return 0;
    }
    return 0;
}