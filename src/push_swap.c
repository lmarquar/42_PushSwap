#include "push_swap.h"

int	sort5(t_list **a, t_list **b)
{
	int save;

	pb(a, b);
	pb(a, b);
	if ((*a)->x > (*a)->next->x)
	{
		if ((*a)->next->x > (*a)->next->next->x)
			ra(a);
		sa(*a);
	}
	if ((*b)->x > (*b)->next->x)
		sb(*b);
	save = (*a)->x;
	if ((*a)->x > (*b)->x)
		save = (*b)->x;
	while ((*a)->x < (*b)->x)
		ra(a);
	pa(a, b);
	while ((*a)->x < (*b)->x)
		ra(a);
	pa(a, b);
	while ((*a)->x != save)
		ra(a);
	return (1);
}

int	push_swap(t_list **a, t_list **b)
{
	sort5(a, b);
	return (1);
}
