#include "../includes/push_swap.h"

int stack_size(t_stack s, int cnt)
{
	int size;

	size = s.tail - s.head + 1;
	if (size < 0)
		size = cnt + size;
	return (size);
}

void sort_by_pivot(t_dual_stack *ds)
{
	int cnt;
	int num;

	cnt = -1;
	while (++cnt < ds->size)
	{
		num = ds->a.data[increase_idx(ds->a.head, ds->size)];
		if (num < ds->pivot_small)
		{
			pb(ds, 1);
			rb(&(ds->b), 1);
		}
		else if (num > ds->pivot_large)
			pb(ds, 1);
		else
			ra(&(ds->a), 1);
	}
	cnt = -1;
	num = stack_size(ds->a, ds->size) - 3;
	while (++cnt < num)
		pb(ds, 1);
}

void update_sort(t_sort *sort, t_sort temp, t_dual_stack *ds)
{
	sort->a_idx = temp.a_idx;
	sort->b_idx = temp.b_idx;
	sort->command_min = temp.command_min;
	sort->flag = temp.flag;
	sort->a_num = ds->a.data[increase_idx(temp.a_idx, ds->size)];
	sort->b_num = ds->b.data[temp.b_idx];
}

int select_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void count_command(t_dual_stack *ds, t_sort *temp)
{
	// int ra;	 // temp->a_idx - ds->a.head;
	// int rb;	 // temp->b_idx - ds->b.head;
	// int rra; // stack_size(ds->a, ds->size) - temp->a_idx;
	// int rrb; // stack_size(ds->b, ds->size) - temp->b_idx;
	int uu;
	int ud;
	int du;
	int dd;

	uu = select_bigger((temp->a_idx - ds->a.head), (temp->b_idx - ds->b.head)) + 1;
	ud = (temp->a_idx - ds->a.head) + (stack_size(ds->b, ds->size) - temp->b_idx) + 1;
	du = (stack_size(ds->a, ds->size) - temp->a_idx) + (temp->b_idx - ds->b.head) + 1;
	dd = select_bigger((stack_size(ds->a, ds->size) - temp->a_idx), (stack_size(ds->b, ds->size) - temp->b_idx)) + 1;

	if (uu < ud && uu < du && uu < dd)
	{
		temp->command_min = uu;
		temp->flag = UU;
	}
	else if (ud < uu && ud < du && ud < dd)
	{
		temp->command_min = ud;
		temp->flag = UD;
	}
	else if (du < uu && du < ud && du < dd)
	{
		temp->command_min = du;
		temp->flag = DU;
	}
	else
	{
		temp->command_min = dd;
		temp->flag = DD;
	}
}

void do_uu(t_dual_stack *ds, t_sort sort)
{
	printf("UU\n");
	while (ds->a.data[increase_idx(ds->a.head, ds->size)] != sort.a_num && ds->b.data[increase_idx(ds->b.head, ds->size)] != sort.b_num)
		rr(ds, 1);
	while (ds->a.data[increase_idx(ds->a.head, ds->size)] != sort.a_num)
		ra(&ds->a, 1);
	while (ds->b.data[increase_idx(ds->b.head, ds->size)] != sort.b_num)
		rb(&ds->b, 1);
	pa(ds, 1);
}

void do_ud(t_dual_stack *ds, t_sort sort)
{
	// printf("UD\n");

	// printf("sort.a_num : %d\n", sort.a_num);
	while (ds->a.data[increase_idx(ds->a.head, ds->size)] != sort.a_num)
		ra(&ds->a, 1);
	while (ds->b.data[increase_idx(ds->b.head, ds->size)] != sort.b_num)
		rrb(&ds->b, 1);
	pa(ds, 1);
}

void do_du(t_dual_stack *ds, t_sort sort)
{
	// printf("DU\n");

	while (ds->a.data[increase_idx(ds->a.head, ds->size)] != sort.a_num)
		rra(&ds->a, 1);
	while (ds->b.data[increase_idx(ds->b.head, ds->size)] != sort.b_num)
		rb(&ds->b, 1);
	pa(ds, 1);
}

void do_dd(t_dual_stack *ds, t_sort sort)
{
	// printf("DD\n");

	while (ds->a.data[increase_idx(ds->a.head, ds->size)] != sort.a_num && ds->b.data[increase_idx(ds->b.head, ds->size)] != sort.b_num)
		rrr(ds, 1);
	while (ds->a.data[increase_idx(ds->a.head, ds->size)] != sort.a_num)
		rra(&ds->a, 1);
	while (ds->b.data[increase_idx(ds->b.head, ds->size)] != sort.b_num)
		rrb(&ds->b, 1);
	pa(ds, 1);
}

void do_sort(t_dual_stack *ds, t_sort sort)
{
	if (sort.flag == UU)
		do_uu(ds, sort);
	else if (sort.flag == UD)
		do_ud(ds, sort);
	else if (sort.flag == DU)
		do_du(ds, sort);
	else
		do_dd(ds, sort);
}

int biggest_idx(t_stack s)
{
	int i;
	int idx;
	int biggest;

	i = increase_idx(s.head, s.size);
	biggest = -2147483648;
	while (i != increase_idx(s.tail, s.size))
	{
		if (biggest < s.data[i])
		{
			idx = i;
			biggest = s.data[i];
		}
		i = increase_idx(i, s.size);
	}
	return idx;
}

int smallest_idx(t_stack s)
{
	int i;
	int idx;
	int smallest;

	i = increase_idx(s.head, s.size);
	smallest = 2147483647;
	while (i != increase_idx(s.tail, s.size))
	{
		if (smallest > s.data[i])
		{
			idx = i;
			smallest = s.data[i];
		}
		i = increase_idx(i, s.size);
	}
	return idx;
}

void sort_a(t_stack *a)
{
	int smallest;
	int idx;
	int stack_size_a;

	stack_size_a = stack_size(*a, a->size);
	idx = smallest_idx(*a);
	smallest = a->data[idx];
	// printf("smallest : %d\n", smallest);
	if (idx < stack_size_a / 2)
	{
		while (smallest != a->data[increase_idx(a->head, a->size)])
			ra(a, 1);
	}
	else
	{
		while (smallest != a->data[increase_idx(a->head, a->size)])
			rra(a, 1);
	}
}

void push_num_to_a(t_dual_stack *ds)
{
	t_sort sort;
	t_sort temp;
	int b_stack_size;
	int num;

	b_stack_size = stack_size(ds->b, ds->size);
	temp.b_idx = increase_idx(ds->b.head, ds->size);
	sort.command_min = 2147483647;
	while (temp.b_idx != increase_idx(ds->b.tail, ds->size))
	{
		temp.a_idx = increase_idx(ds->a.head, ds->size);
		num = ds->b.data[temp.b_idx];
		while (temp.a_idx != ds->a.tail)
		{
			if (ds->a.data[temp.a_idx] < num && num < ds->a.data[increase_idx(temp.a_idx, ds->size)])
			{
				count_command(ds, &temp);
				break;
			}
			temp.a_idx = increase_idx(temp.a_idx, ds->size);
		}
		if (temp.a_idx == ds->a.tail)
		{
			// if (ds->a.data[temp.a_idx] < num)
			// 	temp.a_idx = increase_idx(biggest_idx(ds->a), ds->size);
			// else
			// 	temp.a_idx = smallest_idx(ds->a);
			temp.a_idx = ds->a.head;
			if (temp.b_idx < b_stack_size / 2)
			{
				temp.command_min = temp.b_idx + 1;
				temp.flag = UU;
			}
			else
			{
				temp.command_min = b_stack_size - temp.b_idx + 1;
				temp.flag = UD;
			}
		}
		if (temp.command_min < sort.command_min)
			update_sort(&sort, temp, ds);
		temp.b_idx = increase_idx(temp.b_idx, ds->size);
	}
	do_sort(ds, sort);
	sort_a(&ds->a);
	// test(ds->a);
	// test(ds->b);
}

void sort(t_dual_stack *ds)
{
	// int	stack_size;
	// stack_size = stack_size(ds->a, ds->size);
	// printf("size: %d\n", stack_size(ds->a, ds->size));
	// printf("ps : %d, pl : %d\n", ds->pivot_small, ds->pivot_large); // test
	/* 6개 이상 -> pivot 사용 */
	sort_by_pivot(ds);
	while (1)
	{
		if (is_sorted(ds->a) && is_empty(ds->b))
			break;
		push_num_to_a(ds);
	}
}