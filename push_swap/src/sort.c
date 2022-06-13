#include "../includes/push_swap.h"

int stack_size(t_stack s, int cnt)
{
	int size;

	size = s.tail - s.head;
	if (size < 0)
		size = cnt + size + 1;
	return (size);
}

int top(t_stack s)
{
	return (s.data[increase_idx(s.head, s.size)]);
}

int bottom(t_stack s)
{
	return (s.data[s.tail]);
}

void sort_by_pivot(t_dual_stack *ds)
{
	int i;
	int num;
	int size;

	size = stack_size(ds->a, ds->size);
	i = increase_idx(ds->a.head, ds->size);
	while (size--)
	{
		num = top(ds->a);
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
	while (stack_size(ds->a, ds->size) > 3)
		pb(ds, 1);
}

void update_sort(t_sort *sort, t_sort temp, t_dual_stack *ds)
{
	sort->a_idx = temp.a_idx;
	sort->b_idx = temp.b_idx;
	sort->command_min = temp.command_min;
	sort->flag = temp.flag;
	sort->a_num = ds->a.data[temp.a_idx];
	sort->b_num = ds->b.data[temp.b_idx];
}

int select_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// int ft_abs(int a)
// {
// 	if (a < 0)
// 		return (-a);
// 	return (a);
// }

int count_up(t_stack s, int idx)
{
	int length;

	if (s.head < idx)
		length = idx - s.head - 1;
	else
		length = s.size - (s.head - idx);
	return length;
}

int count_down(t_stack s, int idx)
{
	int length;

	if (s.head < idx)
		length = s.size - idx + s.head + 2;
	else
		length = s.head - idx + 1;
	return length;
}

void count_command(t_dual_stack *ds, t_sort *temp)
{
	int uu;
	int ud;
	int du;
	int dd;

	uu = select_bigger(count_up(ds->a, temp->a_idx), count_up(ds->b, temp->b_idx));
	ud = count_up(ds->a, temp->a_idx) + count_down(ds->b, temp->b_idx);
	du = count_down(ds->a, temp->a_idx) + count_up(ds->b, temp->b_idx);
	dd = select_bigger(count_down(ds->a, temp->a_idx), count_down(ds->b, temp->b_idx));

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
	// printf("UU\n");

	while (top(ds->a) != sort.a_num && top(ds->b) != sort.b_num)
		rr(ds, 1);
	while (top(ds->a) != sort.a_num)
		ra(&ds->a, 1);
	while (top(ds->b) != sort.b_num)
		rb(&ds->b, 1);
	pa(ds, 1);
}

void do_ud(t_dual_stack *ds, t_sort sort)
{
	// printf("UD\n");

	while (top(ds->a) != sort.a_num)
		ra(&ds->a, 1);
	while (top(ds->b) != sort.b_num)
		rrb(&ds->b, 1);
	pa(ds, 1);
	// test(ds->a);
	// test(ds->b);
}

void do_du(t_dual_stack *ds, t_sort sort)
{
	// printf("DU\n");

	while (top(ds->a) != sort.a_num)
		rra(&ds->a, 1);
	while (top(ds->b) != sort.b_num)
		rb(&ds->b, 1);
	pa(ds, 1);
	// test(ds->a);
	// test(ds->b);
}

void do_dd(t_dual_stack *ds, t_sort sort)
{
	// printf("DD\n");

	while (top(ds->a) != sort.a_num && top(ds->b) != sort.b_num)
		rrr(ds, 1);
	while (top(ds->a) != sort.a_num)
		rra(&ds->a, 1);
	while (top(ds->b) != sort.b_num)
		rrb(&ds->b, 1);
	pa(ds, 1);
	// test(ds->a);
	// test(ds->b);
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
	while (1)
	{
		if (smallest > s.data[i])
		{
			idx = i;
			smallest = s.data[i];
		}
		if (i == s.tail)
			break;
		i = increase_idx(i, s.size);
	}
	return idx;
}

void sort_a(t_stack *a)
{
	int smallest;
	int i;
	int stack_size_a;

	stack_size_a = stack_size(*a, a->size);
	i = smallest_idx(*a);
	smallest = a->data[i];
	// printf("head -> tail : %d -> %d\n", a->head, a->tail);
	// printf("idx : %d\n", i);
	if (i < a->head)
		i = stack_size_a - a->head + i + 1;
	else
		i = i - (a->head + 1);
	// printf("i : %d\n", i);
	if (i < stack_size_a / 2)
	{
		// printf("UP\n");
		while (smallest != top(*a))
			ra(a, 1);
	}
	else
	{
		// printf("DOWN\n");
		while (smallest != top(*a))
			rra(a, 1);
	}
}

void set_location_a(t_dual_stack *ds, t_sort *temp, int num)
{
	int left;
	int right;

	temp->a_idx = increase_idx(ds->a.head, ds->size);
	while (1)
	{
		if (temp->a_idx == ds->a.tail)
		{
			if (bottom(ds->a) < num && num < top(ds->a))
				temp->a_idx = increase_idx(ds->a.head, ds->size);
			else
				temp->a_idx = smallest_idx(ds->a);
			count_command(ds, temp);
			break;
		}
		left = ds->a.data[temp->a_idx];
		right = ds->a.data[increase_idx(temp->a_idx, ds->size)];
		if (left < num && num < right)
		{
			count_command(ds, temp);
			temp->a_idx = increase_idx(temp->a_idx, ds->size);
			break;
		}
		temp->a_idx = increase_idx(temp->a_idx, ds->size);
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
	while (1)
	{
		num = ds->b.data[temp.b_idx];
		set_location_a(ds, &temp, num);
		if (temp.command_min < sort.command_min)
			update_sort(&sort, temp, ds);
		if (temp.b_idx == ds->b.tail)
			break;
		temp.b_idx = increase_idx(temp.b_idx, ds->size);
	}
	// test(ds->a);
	// test(ds->b);
	do_sort(ds, sort);
	// if (!is_sorted(ds->a)) // test
	// {
	// 	printf("sort num : %d\n", sort.b_num);
	// 	printf("a_num: %d\n", sort.a_num);
	// 	printf("SORT ERROR\n");
	// 	test(ds->a);
	// 	test(ds->b);
	// 	error_exit();
	// }
	// test(ds->a);
	// test(ds->b);
}

void sort(t_dual_stack *ds)
{
	int size;

	size = ds->size;
	if (size == 2)
		sa(&ds->a, 1);
	else if (size == 3)
		sort_three(&ds->a);
	else if (size <= 5)
		sort_five(ds);
	else
	{
		sort_by_pivot(ds);
		sort_three(&(ds->a));
		while (1)
		{
			if (is_empty(ds->b))
				break;
			push_num_to_a(ds);
		}
		sort_a(&ds->a);
		// test(ds->a);
	}
}