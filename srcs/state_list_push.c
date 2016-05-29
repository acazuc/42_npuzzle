#include "npuzzle.h"

void state_list_push(t_state_list **lst, t_state *state)
{
	t_state_list *new;

	if (!(new = malloc(sizeof(*new))))
	{
		ft_putendl_fd("npuzzle: failed to malloc new state elem", 2);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->state = state;

	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	new->next = *lst;
	*lst = new;
}
