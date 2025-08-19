#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "its_header.h"

void print_stack(Stack *s)
{
    while (s != NULL)
    {
        printf("%c -- %d\n", s->c, s->n);
        s = s->below;
    }
    return;
}

void pop(Stack **s)
{
    Stack *t = *s;
    *s = (*s)->below;
    free(t);
}

char* int_to_string(int num)
{
    // Declare head
    Stack *s = NULL;

    // Create stack node for each number in integer
    // with corresponsing order number.
    while (num > 0)
    {
        char c = '0' + num % 10;

        Stack *t = malloc(sizeof(Stack));
        t->below = s;
        t->c = c;
        t->n = s ? s->n + 1 : 1;
        s = t;

        num /= 10;
    }

    // Create string buffer based on number length
    int length = s->n;
    char *buffer = malloc(length + 1);
    buffer[length] = '\0';

    // Pop from stack in to buffer to reverse number
    while (s)
    {
        char c = s->c;
        buffer[length - s->n] = c;
        pop(&s);
    }

    // Free head
    free(s);

    return buffer;
}