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
    int size;
} t_stack;

typedef struct s_dual_stack
{
    t_stack a;
    t_stack b;
    int pivot_small;
    int pivot_large;
} t_dual_stack;

void error_exit();
void init_stack(int argc, char **argv, int cnt, t_dual_stack *ds);
int is_duplicate(int *data, int num, int cnt);

void ft_sort(t_dual_stack *ds);

int count_args(int argc, char **argv);

void test(t_stack s);

int is_empty(t_stack s);

int increase_idx(int i, int size);
int decrease_idx(int i, int size);

void stack_push(t_stack *s, int num);
int stack_pop(t_stack *s);

void pa(t_dual_stack *ds, int do_print);
void pb(t_dual_stack *ds, int do_print);

void ra(t_stack *a, int do_print);
void rb(t_stack *b, int do_print);
void rr(t_dual_stack *ds, int do_print);

void rra(t_stack *a, int do_print);
void rrb(t_stack *b, int do_print);
void rrr(t_dual_stack *ds, int do_print);

void sa(t_stack *a, int do_print);
void sb(t_stack *b, int do_print);
void ss(t_dual_stack *ds, int do_print);
#endif