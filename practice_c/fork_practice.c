#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void count_print(){
    int counter = 0;
    while(counter < 3){
        printf("%d\n", counter);
        counter++;
    }
    return;
}

int main(int argc, char* argv[]){
    int pid = (int) getpid();

    int num = fork();

    if(num < 0){
        printf("Fork failed");
        exit(1);
    }
    else if (num == 0){
        printf("Child\n");

        char* arr[2] = {"./foo2", NULL};
        int res = execvp(arr[0], arr);
    }
    else{
        int result = wait(NULL);
        printf("Parent PID: %d\nChild PID: %d\n", pid, num);
    }

    return 0;
}