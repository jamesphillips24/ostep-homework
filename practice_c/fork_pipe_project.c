#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct Stack{
    struct Stack* below;
    char c;
    int n;
} Stack;

void print_stack(Stack* s){
    while(s != NULL){
        printf("%c -- %d\n", s->c, s->n);
        s = s->below;
    }
    return;
}

void pop(Stack** s){
    Stack* t = *s;
    *s = (*s)->below;
    free(t);
}

char* int_to_string(int num){
    // Declare head
    Stack* s = NULL;

    // Create stack node for each number in integer
    // with corresponsing order number.
    while(num > 0){
        char c = '0' + num%10;

        Stack* t = malloc(sizeof(Stack));
        t->below = s;
        t->c = c;
        t->n = s ? s->n + 1 : 1;
        s = t;

        num /= 10;
    }

    // Create string buffer based on number length
    int length = s->n;
    char* buffer = malloc(length + 1);
    buffer[length] = '\0';

    // Pop from stack in to buffer to reverse number
    while(s){
        char c = s->c;
        buffer[length - s->n] = c;
        pop(&s);
    }

    // Free head
    free(s);

    return buffer;
}

int main(int argc, char *argv[])
{
    char* buffer = int_to_string(756);
    printf("%s\n", buffer);

    int pipe_arr[2];
    pipe(pipe_arr);
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