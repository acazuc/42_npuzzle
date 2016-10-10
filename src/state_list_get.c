/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_list_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 01:38:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/10 01:39:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state_list *state_list_get(t_env *env, t_state_list *lst, t_state *state)
{
	t_state_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if (state_equals(env, tmp->state, state))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

