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
    int size;
} t_dual_stack;

enum e_sort_three
{
    BAC = 1,
    CBA = 2,
    CAB = 3,
    ACB = 4,
    BCA = 5
};

enum e_sort_flag
{
    UU = 1,
    UD = 2,
    DU = 3,
    DD = 4
};

typedef struct s_sort
{
    int a_idx;
    int b_idx;
    int a_num;
    int b_num;
    int command_min;
    enum e_sort_flag flag;
} t_sort;

int decrease_idx(int i, int size);
void error_exit();
int increase_idx(int i, int size);
int stack_is_empty(t_stack s);
int stack_is_sorted(t_stack a);
int main(int argc, char **argv);
int stack_pop(t_stack *s);
void stack_push(t_stack *s, int num);
// void test(t_stack s);

int bottom(t_stack s);
void bubble_sort(int *data, int size);
int is_duplicate(int *data, int num, int cnt);
enum e_sort_three compare_three(int top, int middle, int bottom);
int count_args(int argc, char **argv);
int count_argv(char *str);
void count_command(t_dual_stack *ds, t_sort *temp);
int count_down(t_stack s, int idx);
int count_up(t_stack s, int idx);
int *data_cpy(int *data, int size);
void do_dd(t_dual_stack *ds, t_sort sort);
void do_du(t_dual_stack *ds, t_sort sort);
void do_sort(t_dual_stack *ds, t_sort sort);
void do_ud(t_dual_stack *ds, t_sort sort);
void do_uu(t_dual_stack *ds, t_sort sort);
void init_pivot(t_dual_stack *ds);
void init_stack(int argc, char **argv, int size, t_dual_stack *ds);
t_stack init_stack_a(int argc, char **argv, int size);
int *init_stack_a_data(int argc, char **argv, int size);
t_stack init_stack_b(int size);
void pa(t_dual_stack *ds, int do_print);
void pb(t_dual_stack *ds, int do_print);
void push_num_to_a(t_dual_stack *ds);
void ra(t_stack *a, int do_print);
void rb(t_stack *b, int do_print);
void rr(t_dual_stack *ds, int do_print);
void rra(t_stack *a, int do_print);
void rrb(t_stack *b, int do_print);
void rrr(t_dual_stack *ds, int do_print);
void sa(t_stack *a, int do_print);
void sb(t_stack *b, int do_print);
int select_bigger(int a, int b);
void set_location_a(t_dual_stack *ds, t_sort *temp, int num);
int smallest_idx(t_stack s);
void sort(t_dual_stack *ds);
void sort_a(t_stack *a);
void sort_by_pivot(t_dual_stack *ds);
void sort_five(t_dual_stack *ds);
void sort_greedy(t_dual_stack *ds);
void sort_three(t_stack *a);
void ss(t_dual_stack *ds, int do_print);
int stack_size(t_stack s, int cnt);
int top(t_stack s);
void update_sort(t_sort *sort, t_sort temp, t_dual_stack *ds);
void free_all(char **str, int size);
#endif