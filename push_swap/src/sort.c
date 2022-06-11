#include "../includes/push_swap.h"

int stack_size(t_stack s, int cnt)
{
	int size;

	size = s.tail - s.head - 1;
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
	while (++cnt < stack_size(ds->a, ds->size) - 3)
		pb(ds, 1);
}

void sort(t_dual_stack *ds)
{
	// int	stack_size;
	// stack_size = stack_size(ds->a, ds->size);
	// printf("size: %d\n", stack_size(ds->a, ds->size));
	// printf("ps : %d, pl : %d\n", ds->pivot_small, ds->pivot_large); // test
	/* 6개 이상 -> pivot 사용 */
	sort_by_pivot(ds);
	// while (1)
	// {
	// 	if (is_sorted(ds->a) && stack_size(ds->a, ds->a.size) == ds->a.size)
	// 		break;
	// }
}