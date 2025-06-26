#include "push_swap.h"

int		is_in_chunk(t_node *node, int start, int end)
{
	return (node->index >= start && node->index <= end);
}


int     find_pos_in_chunk(t_head *pile_a, int start, int end)
{
    int     pos;
    t_node  *tmp;

    pos = 0;
    tmp = pile_a->first;
    while (tmp)
    {
        if (is_in_chunk(tmp, start, end))
			return (pos);
        ++pos;
        tmp = tmp->next;
    }
    return (-1);
}


void	rotate_chunk_a(t_head *pile_a, int pos)
{
	if (pos <= (pile_a->size / 2))
	{
		while (pos--)
			rotate_a(pile_a);
	}
	else
	{
		pos = pile_a->size - pos;
		while (pos--)
			reverse_rotate_a(pile_a);
	}
}			

int     find_pos_max_b(t_head *pile_b)
{
    int     pos;
    int     max;
    int     pos_max;
    t_node  *tmp;

    max = INT_MIN;
    pos = 0;
    tmp = pile_b->first;
    while (tmp)
    {
        if (tmp->val >= max)
        {
            max = tmp->val;
            pos_max = pos;
        }
        ++pos;
        tmp = tmp->next;
    }
    return (pos_max);
}

void    rotate_chunk_b(t_head *pile_b, int pos_max)
{
    if (pos_max <= (pile_b->size / 2))
    {   
        while (pos_max--)
            rotate_b(pile_b);
    }   
    else
    {   
        pos_max = pile_b->size - pos_max;
        while (pos_max--)
            reverse_rotate_b(pile_b);
    }   
}     

void	last_chunk(t_head *pile_a, t_head *pile_b, int end)
{
	int		pos;

	while ((pos = find_pos_in_chunk(pile_a, 0, end)) != -1)
	{
		rotate_chunk_a(pile_a, pos);
		push_b(pile_b, pile_a);
	}
	while (pile_b->size)
	{
		pos = find_pos_max_b(pile_b);
		rotate_chunk_b(pile_b, pos);
		push_a(pile_a, pile_b);
	}
}

void	chunk_sort(t_head *pile_a, t_head *pile_b)
{
	int		chunk;
	int		end;
	int		start;
	int		pos;

	chunk =	pile_a->size / 5; 
	end = pile_a->size - 1;
	while (end >= chunk)
	{
		start = end - chunk + 1;
		while ((pos = find_pos_in_chunk(pile_a, start, end)) != -1)
		{
			rotate_chunk_a(pile_a, pos);
			push_b(pile_b, pile_a);
		}
		while (pile_b->size)
		{
			pos = find_pos_max_b(pile_b);
			rotate_chunk_b(pile_b, pos);
			push_a(pile_a, pile_b);
		}
		end = start - 1;
	}
	last_chunk(pile_a, pile_b, pile_a->size - 1);	
}
