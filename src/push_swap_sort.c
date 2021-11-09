#include "push_swap.h"

int find_median2(t_list *a, t_list *temp, int size, int med)
{
	int		i;
	int		t;

	while (temp)
	{
		if (temp->x < med)
			med = temp->x;
		temp = temp->next;
	}
	i = -1;
	while (++i < size)
	{
		t = med;
		med = INT32_MAX;
		temp = a;
		while (temp)
		{
			if (temp->x < med && temp->x > t)
				med = temp->x;
			temp = temp->next;
		}
	}
	return (med);
}

int	find_median(t_list *a)
{
	int		med;
	int		size;
	t_list	*temp;

	temp = a;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	size = size / 2;
	med = INT32_MAX;
	temp = a;
	med = find_median2(a, temp, size, med);
	return (med);
}
/*
int	recursive_magic(t_list **a, t_list **b, int size)
{
	size = size / 2;

	
	return (0);
}
*/
int	sort(t_list **a, t_list **b)
{
	int	med;
	int	size;

	med = find_median(*a);
	size = get_size(*a);
	while (1)
	{
		med = find_median(*a);
		size = get_size(*a);
		if (size <= 2)
			break ;
		while (size > 0)
		{
			if ((*a)->x < med)
				pb(a, b);
			else
				ra(a);
			size--;
		}
	}
	if ((*a)->x > (*a)->next->x)
		ra(a);
	if ((*b)->x < (*b)->next->x)
		sb(*b);
	pa(a, b);

	return (0);
}