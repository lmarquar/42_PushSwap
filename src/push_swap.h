#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

# include <stdio.h>
typedef struct s_list
{
	int				x;
	struct s_list	*next;
}	t_list;
int		push_swap(t_list **a, t_list **b);
long	ft_atoicheck(char *nptr);
int		err(void);
int		sa(t_list *a);
int		sb(t_list *b);
int		ss(t_list *a, t_list *b);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
int		rra(t_list **a);

#endif