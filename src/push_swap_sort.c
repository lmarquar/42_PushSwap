#include "push_swap.h"

int	sort3(t_list **a, int k)
{
    printf("k: %d\n", k);
    if (k == 1)
		return (0);
    if (k == 2)
    {
		if ((*a)->x > (*a)->next->x)
		    ra(a);
		return (0);
    }
    if (k == 3)
    {
		if ((*a)->x > (*a)->next->x && (*a)->x > (*a)->next->next->x)
			ra(a);
		if ((*a)->next->x > (*a)->next->next->x && (*a)->x < (*a)->next->x)
			rra(a);
		if ((*a)->x > (*a)->next->x)
			sa(*a);
    }
	return (0);
}

int	recursive_one(t_list **a, t_list **b)
{
    int m;
    int	k;
    int i;
    int	pos;

    if (*b)
		pos = (*b)->p + 1;
    else
		pos = 1;
    k = get_size(*a);
    if (k <= 3)
    {
		sort3(a, k);
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
	recursive_one(a, b);

    return (0);
}

int	recursive_two(t_list **a, t_list **b)
{
    int k;
    int m;
    int	pos;
	int npos;

    pos = (*b)->p;
	npos = pos * 10;
	if (npos < (*a)->p)
		npos = (*a)->p;
    k = get_size(*b);
	if (k == 1)
	{
		pa(a, b);
		(*a)->p = npos;
		return (0);
	}
    if (k <= 2) 
    {
		if ((*b) < (*b)->next)
		    sb(*b);
		pa(a, b);
		(*a)->p = npos;
		pa(a, b);
		(*a)->p = npos;
		return (0);
    }
    k = get_size(*b);
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
	//reversepart:
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
	recursive_two(a, b);
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
    recursive_one(a, b);
	printf("\n\n\n");	
    recursive_two(a, b); 
    recursive_two(a, b); 
/*    printf("hhhhh%d", checkifordered(*a));
    if (checkifordered(*a))
		recursive_one(a, b);
    recursive_two(a, b);
   */ 
    return (0);
}
