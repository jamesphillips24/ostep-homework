#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int num = 0;
    char data;
    printf("pid: %d\n", getpid());
    int fork_res = fork();

    if(fork_res < 0){
        printf("Fork failed");
        exit(1);
    }
    else if(fork_res == 0){
        int result = wait(NULL);
        printf("Child: %d\n", result);
    }
    else{
        printf("Parent\n");
    }
    return 0;
}