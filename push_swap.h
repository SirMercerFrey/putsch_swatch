#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct      s_head
{
    struct s_node   *first;
    int             size;
}                   t_head;

typedef struct      s_node
{
    struct s_node   *next;
    int             val;
    int             index;
}                   t_node;

void    swap_int(int *a, int *b);
int     partition(int *tab, int start, int end);
void    quick_sort(int *tab, int start, int end);
void    print_tab(int *tab, int size);
void	give_index(t_head *pile, int *tab);
int		*create_tab(t_head *pile);
void	swap_a(t_head *pile_a);
void	rotate_a(t_head *pile_a);
void	rotate_b(t_head *pile_b);
void	reverse_rotate_a(t_head *pile_a);
void	reverse_rotate_b(t_head *pile_b);
void	push_b(t_head *pile_b, t_head *pile_a);
void	push_a(t_head *pile_a, t_head *pile_b);
void    radix_sort(t_head *pile_a, t_head *pile_b);
int     is_in_chunk(t_node *node, int start, int end);
int     find_pos_in_chunk(t_head *pile_a, int start, int end);
void    rotate_chunk_a(t_head *pile_a, int pos_max);
int     find_pos_max_b(t_head *pile_b);
void    rotate_chunk_b(t_head *pile_b, int pos_max);
void    last_chunk(t_head *pile_a, t_head *pile_b, int end);
void    chunk_sort(t_head *pile_a, t_head *pile_b);

#endif
