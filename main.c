#include "src/push_swap.h"

int printlists(t_list *a, t_list *b)
{
	char	*s;
	char	c;
	int		i;

	write(1, "a:\n", 3);
	while (a)
	{
		s = ft_itoa(a->x);
		i = 0;
		while (s[i])
			write(1, &s[i++], 1);
		write(1, ", ", 2);
		c = a->p + '0';
		write(1, &c, 1);
		free(s);
		
		a = a->next;
		write(1, "\n", 1);
	}
	write(1, "\nb:\n", 4);
	while (b)
	{
		s = ft_itoa(b->x);
		i = 0;
		while (s[i])
			write(1, &s[i++], 1);
		write(1, ", ", 2);
		c = b->p + '0';
		write(1, &c, 1);
		b = b->next;
		write(1, "\n", 1);
	}
	return (1);
}

int	fill_list(t_list *a, int argc, char **argv)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = a;
	while (i < (argc - 1))
	{
		if (!temp || ft_atoicheck(argv[i + 1]) == (long)2147483648)
			return (1);
		temp->x = (int)ft_atoicheck(argv[i + 1]);
		temp->p = 0;
		if (!(++i < (argc - 1)))
			break ;
		temp->next = malloc(sizeof(t_list *));
		temp = temp->next;
	}
	temp->next = NULL;
	return (0);
}

int	check_list(t_list *a)
{
	t_list	*t1;
	t_list	*t2;
	int		i1;
	int		i2;

	t1 = a;
	if (a->next == NULL)
		return (0);
	i1 = 0;
	while (t1)
	{
		i2 = 0;
		t2 = a;
		while (t2)
		{
			if (t1->x == t2->x && i1 != i2)
				return (1);
			t2 = t2->next;
			i2++;
		}
		t1 = t1->next;
		i1++;
	}
	return (0);
}

int	free_list(t_list *a)
{
	t_list	*temp;

	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;

	a = malloc(sizeof(t_list *));
	b = NULL;
	if (fill_list(a, argc, argv) != 0)
	{
		free_list(a);
		return(1);
	}
	if (check_list(a) != 0)
	{
		free_list(a);
		return(1);
	}
	push_swap(&a, &b);
	printlists(a, b);
	return (1);
}
