#include "src/push_swap.h"

int printlists(t_list *a, t_list *b)
{
	char	*s;
	int		i;

	write(1, "a:\n", 3);
	while (a)
	{
		s = ft_itoa(a->x);
		i = 0;
		while (s[i])
			write(1, &s[i++], 1);
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
		b = b->next;
		write(1, "\n", 1);
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_list		*temp;
	int			i;

	a = malloc(sizeof(t_list *));
	b = NULL;
	i = 0;
	temp = a;
	while (i < (argc - 1))
	{
		if (!temp || ft_atoicheck(argv[i + 1]) == (long)2147483648)
			return (err());
		temp->x = (int)ft_atoicheck(argv[i + 1]);
		if (!(++i < (argc - 1)))
			break ;
		temp->next = malloc(sizeof(t_list *));
		temp = temp->next;
	}
	temp->next = NULL;
	push_swap(&a, &b);
	printlists(a, b);
	return (1);
}
