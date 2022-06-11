#include "../includes/push_swap.h"

int stack_size(t_stack s, int cnt)
{
	int size;

	size = s.tail - s.head;
	if (size < 0)
		size = cnt - size;
	return (size);
}

void ft_sort(t_dual_stack *ds)
{
	// int	stack_size;
	// stack_size = stack_size(ds->a, ds->size);
	// printf("size: %d\n", stack_size(ds->a, ds->size));
	pb(ds, 1);
	pb(ds, 1);
	pb(ds, 1);
	test(ds->b);
	rrb(&(ds->b), 1);
	printf("head : %d\n", ds->b.data[ds->b.head]);
	test(ds->b);
}