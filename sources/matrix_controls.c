#include "fdf.h"

t_point			*new_point(t_point *prev)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	new->prev = prev;
	new->next = NULL;
	return (new);
}

// void				ft_free_matrix(t_matrix **matrix)
// {
//
// }
