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
    t_stack a;
    t_stack b;
    int size;
} t_dual_stack;

int main(int argc, char **argv);
void error_exit();
void init_stack(int argc, char **argv, int cnt, t_dual_stack *ds);
int is_duplicate(t_stack a, int num, int cnt);
int count_args(int argc, char **argv);

#endif