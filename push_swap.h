#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

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

#endif
