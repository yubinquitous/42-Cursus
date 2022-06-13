#include "../../includes/push_swap.h"

void sort(t_dual_stack *ds)
{
	if (ds->size == 2)
		sa(&ds->a, 1);
	else if (ds->size == 3)
		sort_three(&ds->a);
	else if (ds->size <= 5)
		sort_five(ds);
	else
		sort_greedy(ds);
}