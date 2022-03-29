#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libft/libft.h"

# include <stdio.h>
typedef struct s_list
{
	int	x;
	int	p;	
	struct s_list	*next;
}	t_list;
int		push_swap(t_list **a, t_list **b);
long	ft_atoicheck(char *nptr);
int		err(void);
int		get_size(t_list *x);
int		get_size_end(t_list *x);
int		round_2up10(int x);

int		sa(t_list *a);
int		sb(t_list *b);
int		ss(t_list *a, t_list *b);
int		pa(t_list **a, t_list **b);
int		pb(t_list **a, t_list **b);
int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);
int		rra(t_list **a);
int		rrb(t_list **b);
int		sort(t_list **a, t_list **b);

int		find_median(t_list *a);
int		find_median_end(t_list *a);
#endif
