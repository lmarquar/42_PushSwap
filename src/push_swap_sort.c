#include "push_swap.h"

int recursive_first(t_list **a, t_list **b)
{
	int m;
	int	k;
	int i;
	int	p;

	if (!(*b))
		p = 1;
	else
		p = (*b)->p + 1;
	k = get_size(*a);
	if (k <= 3)
	{
		sort3(a, b, k);
		return (0);
	}
	m = find_median(*a);
	i = 0;
	while (i < k)
	{
		if ((*a)->x <= m)
		{
			pb(a, b);
			(*b)->p = p;
			if ((*b)->x == m)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
	rrb(b);
	if (sorted(*a))
		return (0);
	recursive_first(a, b);
	return (1);
}

int	recursive_atob(t_list **a, t_list **b)
{
	int m;
	int	k;
	int i;
	int	p;

	if ((*a)->p >= get_last_p(*a)) 
	{
		p = (*b)->p + 1;
		k = get_size(*a);
		if (k <= 3)
		{
			sort3(a, b, k);
			return (0);
		}
		m = find_median(*a);
		i = 0;
		while (i < k)
		{
			if ((*a)->x <= m)
			{
				pb(a, b);
				(*b)->p = p;
				if ((*b)->x == m)
					rb(b);
			}
			else
				ra(a);
			i++;
		}
		rrb(b);
		if (sorted(*a))
			return (0);
	}

	//reverspart
	p = (*b)->p + 1;
	k = get_size_end(*a);
	if (k <= 3)
	{
		p = k;
		while (p-- > 0)
			rra(a);
		sort3(a, b, k);
		return (0);
	}
	m = find_median_end(*a);
	i = 0;
	while (i < k)
	{
		rra(a);
		if ((*a)->x <= m)
		{
			pb(a, b);
			(*b)->p = p;
			if ((*b)->x == m)
				rb(b);
		}
		i++;
	}
	rrb(b);

	if (!sorted(*a))
		recursive_atob(a, b);
	else
		p_to_null(*a);	
	return (0);
}

int	recursive_main(t_list **a, t_list **b)
{
	if (!sorted(*a))
		recursive_atob(a, b);
	else if ((*b) != NULL)
		p_to_null(*a);
	else
		return (0);

	int k;
	int m;
	int	p;
	int np;

	if ((*b)->x > get_last(*b))
	{
		if (!(*b))
			return (0);
		if ((*b)->x == get_biggest(*b))
			pa(a, b);
		if (!(*b))
			return (0);
		k = get_size(*b);
		p = (*b)->p;
		np = (*a)->p + 1;	
		if (k <= 3)
		{
			sort3_b_pa(a, b, k);
			recursive_main(a, b);
		}
		else if ((*b)->p == p && k > 0)
		{
			m = find_median(*b);
			while ((*b)->p == p && k > 0)
			{
				if ((*b)->x >= m)
				{
					pa(a, b);
					(*a)->p = np;
					if ((*a)->x == m)
						ra(a);
				}
				else
					rb(b);
				k--;
			}
			rra(a);
		}
	}

	//recursively compute new elements on stack a
	if (!sorted(*a))
		recursive_main(a, b);
	if (!(*b))
		return (0);
	k = get_size_end(*b);
	m = k;
	if (k <= 3 && (*b)->x < get_last(*b))
	{
		while (m-- > 0)
			rrb(b);
		sort3_b_pa(a, b, k);
	}
	if (!*b)
		return (0);
	//reversepart:
	if ((*b)->x < get_last(*b))
	{
		np = np + 1;
		k = get_size_end(*b);
		m = find_median_end(*b);
		while (k > 0)
		{
			rrb(b);
			if ((*b)->x >= m)
			{
				pa(a, b);
				(*a)->p = np;
				if ((*a)->x == m)
					ra(a);
			}
			k--;
		}
		rra(a);
	}
	recursive_main(a, b);
	return (0);
}

int	sort(t_list **a, t_list **b)
{
//	while(!recursive_first(a, b))
//		;
	recursive_first(a, b);
	recursive_main(a, b);
	return (0);
}
