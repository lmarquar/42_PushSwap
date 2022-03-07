#include "push_swap.h"

int find_median2(t_list *a, int size, int med, int k)
{
	int		i;
	int		t;
	t_list		*temp;

	temp = a;
	while (temp/* && temp->p == k*/)
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
		while (temp/* && temp->p == k*/)
		{
			if (temp->x < med && temp->x > t)
				med = temp->x;
			temp = temp->next;
		}
	}
	k = k + 1;
	return (med);
}

int	find_median(t_list *a)
{
	int		med;
	int		size;
	int		k;
	t_list		*temp;

	temp = a;
	k = a->p;
	size = 0;
	while (temp/* && temp->p == k*/)
	{
		size++;
		temp = temp->next;
	}
	size = size / 2;
	med = INT32_MAX;
	temp = a;
	med = find_median2(a, size, med, k);
	return (med);
}

int		get_size(t_list *x)
{
	int	res;

	res = 0;
	while (x)
	{
		x = x->next;
		res++;
	}
	return (res);
}

long	ft_atoicheck(char *nptr)
{
	int			i;
	long		res;
	int			x10;

	i = 0;
	x10 = 1;
	res = 0;
	if (nptr[i] == '-')
		x10 = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (!(nptr[i] > '0' && nptr[i] <= '9'))
		return ((long)2147483648);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		i++;
	if (nptr[i] || i-- > 11)
		return ((long)2147483648);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = ((nptr[i--] - '0') * x10) + res;
		x10 = x10 * 10;
	}
	if (res > (long)2147483647 || res < (long) -2147483648)
		return ((long)2147483648);
	return (res);
}

int	err(void)
{
	char	*s;
	int		i;

	s = "Error\n";
	i = 0;
	while (s[i])
	{
		write(1, &(s[i]), 1);
		i++;
	}
	return (-1);
}
