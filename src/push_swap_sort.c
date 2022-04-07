#include "push_swap.h"

int	recursive_atob(t_list **a, t_list **b)
{
	if ((*a)->p >= get_last_p(*a))
		if (!a_to_b(a, b))
			return (0);
	if ((*a)->p < get_last_p(*a))
		if (!a_to_b_rev(a, b))
			return (0);
	if (!sorted(*a))
		recursive_atob(a, b);
	return (0);
}

int	recursive_main(t_list **a, t_list **b)
{
	int	k;

	if (!sorted(*a))
		recursive_atob(a, b);
	else if ((*b) != NULL)
		p_to_null(*a);
	else
		return (0);
	if ((*b)->x > get_last(*b))
	{
		k = b_to_a(a, b);
		if (k == 2)
			recursive_main(a, b);
		else if (!k)
			return (0);
	}
	if ((*b)->x < get_last(*b) && sorted(*a))
		if (!b_to_a_rev(a, b))
			return (0);
	recursive_main(a, b);
	return (0);
}

int	sort(t_list **a, t_list **b)
{
	int	i;

	i = 1;
	while (i)
		i = a_to_b(a, b);
	recursive_main(a, b);
	return (0);
}
