#include "npuzzle.h"

void state_list_remove(t_state_list **lst, t_state *state)
{
	t_state_list *tmp;
	t_state_list *ite;
	t_state_list *prv;

	if (!(*lst))
		return;
	if ((*lst)->state == state)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		return;
	}
	ite = *lst;
	prv = NULL;
	while (ite)
	{
		if (ite->state == state)
		{
			prv->next = ite->next;
			free(ite);
			return;
		}
		prv = ite;
		ite = ite->next;
	}
}
