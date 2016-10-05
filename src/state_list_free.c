#include "npuzzle.h"

void state_list_free(t_state_list *lst)
{
	t_state_list *tmp;
	t_state_list *nxt;

	tmp = lst;
	while (tmp)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
}
