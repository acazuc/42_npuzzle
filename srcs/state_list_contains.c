#include "npuzzle.h"

int state_list_contains(t_env *env, t_state_list *lst, t_state *state)
{
	t_state_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if (state_equals(env, tmp->state, state))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
