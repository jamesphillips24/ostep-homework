#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fork_num = fork();

    if(fork_num < 0){
        printf("Fork failed");
        exit(1);
    }
    else if (fork_num == 0){
        return 0;
    }
    else{
        return 0;
    }

    return 0;
}