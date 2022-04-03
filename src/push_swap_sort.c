#include "push_swap.h"

int p_to_null(t_list *a)
{
	while (a)
	{
		a->p = 0;
		a = a->next;
	}
	return (0);
}

int	sorted(t_list *a)
{
	if (!a)
		return (1);
	if (!(a->next))
		return (1);
	while (a->next)
	{
		if (a->x > a->next->x)
			return (0);	
		a = a->next;
	}
	//p_to_null(a);
	return (1);
}	

int get_last(t_list *x)
{
	if (!x)
		return (0);
	while (x->next)
		x = x->next;
	return (x->x);
}

int get_last_p(t_list *x)
{
	if (!x)
		return (0);
	while (x->next)
		x = x->next;
	return (x->p);
}

int	sort3(t_list **a, t_list **b, int k)
{
	if (k == 1)
		return (0);
	if (k == 2)
	{
		if ((*a)->x > (*a)->next->x)
			sa(*a);
		return (0);
	}
	if (k == 3)
	{
		if ((*a)->x > (*a)->next->x && (*a)->x > (*a)->next->next->x)
			sa(*a);
		if ((*a)->next->x > (*a)->next->next->x && (*a)->x < (*a)->next->x)
		{	
			pb(a, b);
			sa(*a);
			pa(a, b);
		}
		if ((*a)->x > (*a)->next->x)
			sa(*a);
	}
	return (0);
}

int	sort3_b(t_list **a, t_list **b, int k)
{
	if (k == 1)
		return (0);
	if (k == 2)
	{
		if ((*b)->x < (*b)->next->x)
			sb(*b);
		return (0);
	}
	if (k == 3)
	{
		if ((*b)->x < (*b)->next->x && (*b)->x < (*b)->next->next->x)
			sb(*b);
		if ((*b)->next->x < (*b)->next->next->x && (*b)->x > (*b)->next->x)
		{	
			pa(a, b);
			sb(*b);
			pb(a, b);
		}
		if ((*b)->x < (*b)->next->x)
			sb(*b);
	}
	return (0);
}



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
	return (0);
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
//			p_to_null(*a);
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
//		p_to_null(*a);
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
//	p_to_null(*a);	
	return (0);
}


int	recursive_main(t_list **a, t_list **b)
{
	if (!sorted(*a))
		recursive_atob(a, b);
	else if (*b)
		p_to_null(*a);
	else
		return (0);

	int k;
	int m;
	int	p;
	int np;

	if (!(*b))
		return (0);
	k = get_size(*b);
	p = (*b)->p;
	np = (*a)->p + 1;	
	if (k <= 3)
	{
		sort3_b(a, b, k);
		while (k > 0)
		{
			(*b)->p = np;
			pa(a, b);
			k--;
		}
//		p_to_null(*a);
//		recursive_main(a, b);
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

	//recursively compute new elements on stack a
	if (get_size(*a) >= 3 && !sorted(*a))
		recursive_main(a, b);

//	write(1, "\nMARK1:\n", 9);
//	printlists(*a, *b);
	if (!(*b))
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

int	checkifordered(t_list *a)
{
	while (a->next)
	{
		if (a->next->x < a->x)
			return (1);
		a = a->next;
	}
	return (0);
}

int	sort(t_list **a, t_list **b)
{
	recursive_first(a, b);
//	write(1, "\nSTART\n", 9);
	recursive_main(a, b);
//	printlists(*a, *b);
	return (0);
}
