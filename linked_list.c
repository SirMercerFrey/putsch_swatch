#include "push_swap.h"

t_head	*create_pile(void)
{
	t_head		*pile;

	pile = malloc(sizeof(t_head));
	if (!pile)
		return (NULL);
	pile->first = NULL;
	pile->size = 0;
	return (pile);
}

t_node	*create_node(int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->val = val;
	node->index = 0;
	return (node);
}

void	add_stack(t_node *node, t_head **pile)
{

	if (!node || !*pile || !pile)
		return ;
	if (!(*pile)->first)
	{
		(*pile)->first = node;
		++(*pile)->size;
		return ;
	}
	node->next = (*pile)->first;
	(*pile)->first = node;
	++(*pile)->size;
}

void	print_pile(t_head *pile)
{
	t_node	*tmp;

	if (!pile)
		return ;
	tmp = pile->first;
	while (tmp)
	{
		printf("\\__%d__/ [%d]\n", tmp->val, *&(tmp->index)); 
		tmp = tmp->next;
	}
	printf(" pile a (%d elements)\n", pile->size);
}

void	free_pile(t_head *pile)
{
	t_node	*tmp;

	if (!pile)
		return ;
	while (pile->first)
	{
		tmp = pile->first;
		pile->first = pile->first->next;
		free(tmp);	
	}
	free(pile);
}

int		ft_atoi(char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;

	while (*str)
	{
		if (*str == '-')
		{
			sign *= -1;
			++str;
		}
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10 + *str - '0';
			++str;
		}
	}
	return (sign * result);
}

int		main(int argc, char **argv)
{
	int		i;
	int		*tab;
	t_head	*pile_a;

	pile_a = create_pile();
	if (argc < 2)
		return (printf("\n"));
	i = 1;
	while (i < argc)
		add_stack(create_node(ft_atoi(argv[i++])), &pile_a);
	tab = create_tab(pile_a);
	quick_sort(tab, 0, pile_a->size - 1); 
	give_index(pile_a, tab);
	print_pile(pile_a);
	free(tab);
	free_pile(pile_a);
	return (0);
}
