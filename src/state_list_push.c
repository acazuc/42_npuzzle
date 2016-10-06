#include "npuzzle.h"

static void insert(t_state_list **list, t_state_list *lst, t_state_list *prv, t_state_list *crt)
{
	if (!prv)
	{
		crt->next = *list;
		*list = crt;
		return;
	}
	else
	{
		crt->next = lst;
		prv->next = crt;
	}
}

static void push(t_state_list **list, t_state_list *state)
{
	t_state_list *prv;
	t_state_list *lst;

	prv = NULL;
	lst = *list;
	while (lst)
	{
		if (state->state->score <= lst->state->score)
		{
			insert(list, lst, prv, state);
			return;
		}
		prv = lst;
		lst = lst->next;
	}
	prv->next = state;
}

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
	push(lst, new);
}
