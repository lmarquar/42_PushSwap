#include "push_swap.h"


int	sorted(t_list *a)
{
	int i;

	i = 0;
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

int	sort3(t_list **a, t_list **b, int k)
{
    printf("k: %d\n", k);
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
    printf("k: %d\n", k);
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

int	recursive_atob(t_list **a, t_list **b)
{
    int m;
    int	k;
    int i;
    int	pos;

	if (!(*b))
		pos = 1;
	else if ((*b)->p < (*a)->p)
		pos = round_2up10((*a)->p);
	else if (*b)
		pos = (*b)->p + 1;
    k = get_size(*a);
    if (k <= 3)
    {
		sort3(a, b, k);
		return (0);
    }
    m = find_median(*a);
	printf("median: %d\nsize_a_before: %d", m, get_size(*a));
   	i = 0;
    while (i <= k)
    {
		printf("current element: %d i: %d\n", (*a)->x, i);
		if ((*a)->x <= m)
		{
		    pb(a, b);
		    (*b)->p = pos;
			if ((*b)->x == m)
				rb(b);
		}
		else
		    ra(a);
		i++;
    }
    pos++;
	rrb(b);
	if (!sorted(*a))
		recursive_atob(a, b);

    return (0);
}


int	recursive_main(t_list **a, t_list **b)
{
	printf("\nstartofrecursivecall:\n");
	if (!sorted(*a))
		recursive_atob(a, b);

    int k;
    int m;
    int	pos;
	int npos;

	if (!(*b))
		return (0);
    k = get_size(*b);
    pos = (*b)->p;
	npos = round_2up10(pos);
	if (npos < (*a)->p)
		npos = (*a)->p;
	if (k <= 3)
	{
		sort3_b(a, b, k);
		while (k > 0)
		{
			(*b)->p = npos;
			pa(a, b);
			k--;
		}
    }
	else if ((*b)->p == pos && k > 0)
	{
	    m = find_median(*b);
	    printf("med: %d\n", m);
	    while ((*b)->p == pos && k > 0)
	    {
			if ((*b)->x >= m)
			{
			    pa(a, b);
				(*a)->p = npos;
				printf("%d\n", (*a)->x);
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
//	if (get_size(*a) > 3 && !sorted(*a))
//		recursive_main(a, b);

	//reversepart:
	if ((*b)->x < get_last(*b))
	{
		npos = npos + 1;
		k = get_size_end(*b);
		m = find_median_end(*b);
		printf("size_b_end: %d\nfind_med_end: %d\n", k, m);
		while (k > 0)
		{
			rrb(b);
			if ((*b)->x >= m)
			{
				pa(a, b);
				(*a)->p = npos;
				if ((*a)->x == m)
					ra(a);
			}
			k--;
		}
		rra(a);
	}
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
   recursive_main(a, b); 
   recursive_main(a, b); 
   recursive_main(a, b); 
  // recursive_main(a, b); 
  // recursive_main(a, b);

/*    printf("hhhhh%d", checkifordered(*a));
    if (checkifordered(*a))
		recursive_one(a, b);
    recursive_two(a, b);
   */ 
    return (0);
}
