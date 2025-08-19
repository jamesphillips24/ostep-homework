#ifndef ITS_HEADER_H
#define ITS_HEADER_H

typedef struct Stack
{
    struct Stack *below;
    char c;
    int n;
} Stack;

void print_stack(Stack*);
void pop(Stack**);
char* int_to_string(int);

#endif