#include "push_swap.h"

static
int	sort5_2smaltob(t_list **a, t_list **b, int count)
{
	int		i2;
	int		x;
	t_list	*tmp;

	while (--count > -1)
	{
		i2 = 0;
		x = INT32_MAX;
		tmp = (*a);
		while (tmp)
		{
			if (tmp->x < x)
				x = tmp->x;
			tmp = tmp->next;
			i2++;
		}
		while ((*a)->x != x && i2 < 2)
			ra(a);
		while ((*a)->x != x && i2 >= 2)
			rra(a);
		pb(a, b);
	}
	return (0);
}

static
int	sort5(t_list **a, t_list **b)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = *a;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	if (size > 3)
		sort5_2smaltob(a, b, (size - 3));
	if ((*a)->x > (*a)->next->x && (*a)->x > (*a)->next->next->x)
		ra(a);
	if ((*a)->next->x > (*a)->next->next->x && (*a)->x < (*a)->next->x)
		rra(a);
	if ((*a)->x > (*a)->next->x)
		sa(*a);
	pa(a, b);
	pa(a, b);
	return (0);
}

int	push_swap(t_list **a, t_list **b)
{
	t_list *temp;
	int i;

	temp = *a;
	i = 0;
	while(i <= 5 && temp)
	{
		temp = temp->next;
		i++;
	}
	if (i <= 1)
		return (0);
	else if (i <= 2)
	{
		if ((*a)->x > (*a)->next->x)
			sa(*a);
	}
	else if (i <= 5)
		sort5(a, b);
	else
		sort(a, b);
	return (0);
}
