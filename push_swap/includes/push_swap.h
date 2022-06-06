#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> // test
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    int *data;
    int head;
    int tail;
} t_stack;

typedef struct s_dual_stack
{
    t_stack *a;
    t_stack *b;
    int size;
} t_dual_stack;

int main(int argc, char **argv);
void error_exit();

#endif