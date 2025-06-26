/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:00:43 by mcharret          #+#    #+#             */
/*   Updated: 2025/06/23 18:24:30 by mcharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_head *pile_a)
{
	t_node	*tmp;

	if (pile_a->size < 2)
		return ;
	tmp = pile_a->first;
	pile_a->first = pile_a->first->next;
	tmp->next = pile_a->first->next;
	pile_a->first->next = tmp;
	printf("swap_a\n");
}

void	rotate_a(t_head *pile_a)
{
	t_node	*tmp;
	t_node	*current;

	if (pile_a->size < 2)
		return ;
	tmp = pile_a->first;
	pile_a->first = pile_a->first->next;	
	current = pile_a->first;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	printf("rotate_a\n");
}

void	rotate_b(t_head *pile_b)
{
	t_node	*tmp;
	t_node	*current;

	if (pile_b->size < 2)
		return ;
	tmp = pile_b->first;
	pile_b->first = pile_b->first->next;	
	current = pile_b->first;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	printf("rotate_b\n");
}

void	reverse_rotate_a(t_head *pile_a)
{
	t_node	*tmp;
	t_node	*current;

	if (pile_a->size < 2)
		return ;
	current = pile_a->first;
	while (current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = pile_a->first;
	pile_a->first = tmp;
	printf("reverse_rotate_a\n");
}

void	reverse_rotate_b(t_head *pile_b)
{
	t_node	*tmp;
	t_node	*current;

	if (pile_b->size < 2)
		return ;
	current = pile_b->first;
	while (current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = pile_b->first;
	pile_b->first = tmp;
	printf("reverse_rotate_b\n");
}

void	push_b(t_head *pile_b, t_head *pile_a)
{
	t_node	*tmp;

	if (pile_a->size < 1)
		return ;
	tmp = pile_a->first;
	pile_a->first = pile_a->first->next;
	if (pile_b->size > 0)
		tmp->next = pile_b->first;
	else
		tmp->next = NULL;
	pile_b->first = tmp;
	--(pile_a->size);
	++(pile_b->size);
	printf("push_b\n");
}

void	push_a(t_head *pile_a, t_head *pile_b)
{
	t_node	*tmp;

	if (pile_b->size < 1)
		return ;
	tmp = pile_b->first;
	pile_b->first = pile_b->first->next;
	if (pile_a->size > 0)
		tmp->next = pile_a->first;
	else
		tmp->next = NULL;
	pile_a->first = tmp;
	--(pile_b->size);
	++(pile_a->size);
	printf("push_a\n");
}

void	radix_sort(t_head *pile_a, t_head *pile_b)
{
	int		bits;
	int		size;
	int		i;
	int		j;

	bits = 0;
	while (pile_a->size >> bits != 0)
		++bits;
	j = 0;
	while (j < bits)
	{
		size = pile_a->size;
		i = 0;
		while (i < size)
		{
			if ((pile_a->first->index >> j & 1) == 0)
				push_b(pile_b, pile_a);
			else
				rotate_a(pile_a);
			++i;
		}
		while (pile_b->size)
			push_a(pile_a, pile_b);
		++j;
		printf("__________\n");
	}
}
