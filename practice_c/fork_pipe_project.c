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
    while(s->below != NULL){
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

char* int_to_char(int num){
    Stack* s = malloc(sizeof(Stack));
    s->below = NULL;
    s->n = 0;

    int magnitude = 0;
    while(num > 0){
        char c = '0' + num%10;

        Stack* t = malloc(sizeof(Stack));
        t->below = s;
        t->c = c;
        t->n = s->n + 1;
        s = t;

        num /= 10;
        magnitude++;
    }

    int length = s->n;
    char* buffer = malloc(length + 1);
    buffer[length] = '\0';

    while(s->n > 0){
        char c = s->c;
        buffer[length - s->n] = c;
        pop(&s);
    }

    free(s);

    return buffer;
}

int main(int argc, char *argv[])
{
    char* buffer = int_to_char(756);
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