/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:39:27 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/15 13:50:18 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	*data;
	int	head;
	int	tail;
	int	size;
}	t_stack;

typedef struct s_dual_stack
{
	t_stack	a;
	t_stack	b;
	int		pivot_small;
	int		pivot_large;
}	t_dual_stack;

typedef struct s_command_cnt
{
	int	uu;
	int	ud;
	int	dd;
	int	du;
}	t_command_cnt;

enum	e_sort_three
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
	enum e_sort_flag	flag;
	int					a_idx;
	int					b_idx;
	int					a_num;
	int					b_num;
	int					command_min;
}	t_sort;

void	pa(t_dual_stack *ds, int do_print);
void	pb(t_dual_stack *ds, int do_print);
void	ra(t_stack *a, int do_print);
void	rb(t_stack *b, int do_print);
void	rr(t_dual_stack *ds, int do_print);
void	rra(t_stack *a, int do_print);
void	rrb(t_stack *b, int do_print);
void	rrr(t_dual_stack *ds, int do_print);
void	sa(t_stack *a, int do_print);
void	sb(t_stack *b, int do_print);
void	ss(t_dual_stack *ds, int do_print);

int		count_args(int argc, char **argv);

int	 	count_up(t_stack s, int idx);
void	count_command(t_dual_stack *ds, t_sort *temp);

int		is_duplicate(int *data, int num, int cnt);
void	bubble_sort(int *data, int size);
int		*data_cpy(int *data, int size);

void	init_stack(int argc, char **argv, int size, t_dual_stack *ds);

void	push_num_to_a(t_dual_stack *ds);
void	push_num_to_b(t_dual_stack *ds);

void	do_sort(t_dual_stack *ds, t_sort sort);

void	sort_a(t_stack *a);

void	sort_five(t_dual_stack *ds);
void	sort_greedy(t_dual_stack *ds);
void	sort_three(t_stack *a);
void	sort(t_dual_stack *ds);

void	error_exit(void);

int		increase_idx(int i, int size);
int		decrease_idx(int i, int size);
int		smallest_idx(t_stack s);
int		biggest_idx(t_stack s);

int		top(t_stack s);
int		bottom(t_stack s);

int		stack_is_empty(t_stack s);
int		stack_is_sorted(t_stack a);
int		stack_size(t_stack s, int cnt);
void	stack_push(t_stack *s, int num);
int		stack_pop(t_stack *s);

#endif
