#include "push_swap.h"

void	swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		partition(int *tab, int start, int end)
{
	int		i;
	int		j;
	int		pivot;

	i = start;
	j = start;
	pivot = tab[end];
	while (j < end)
	{
		if (tab[j] < pivot)
		{
			swap_int(&tab[i], &tab[j]);
			++i;
		}
		++j;
	}
	swap_int(&tab[i], &tab[end]); 
	return (i);
}

void	quick_sort(int *tab, int start, int end)
{
	int		pivot_index;

	if (start < end)
	{
		pivot_index = partition(tab, start, end);
		quick_sort(tab, start, pivot_index - 1);
		quick_sort(tab, pivot_index + 1, end);
	}
}
 
void	print_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
		printf("%d\n", tab[i++]);
	printf("\n");
}

int		*create_tab(t_head *pile)
{
	int		*tab;
	int		i;
	t_node	*tmp;

	if (!pile)
		return (NULL);
	tab = malloc(sizeof(int) * pile->size);
	if (!tab)
		return (NULL);
	tmp = pile->first;
	i = 0;
	while (tmp && i < pile->size)
	{
		tab[i++] = tmp->val;
		tmp = tmp->next;
	}
	return (tab);
}

void	give_index(t_head *pile, int *tab)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i < pile->size)
	{
		tmp = pile->first;
		while (tmp)
		{
			if (tmp->val == tab[i])
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
		++i;
	}
}
