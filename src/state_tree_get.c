/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_tree_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 23:52:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 11:24:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state	*state_tree_get(t_env *env, t_state_tree *tree, t_state *state, int *is_closed)
{
	t_state_tree *lst;
	int size = env->size * env->size;
	int i = 0;

	lst = tree;
	while (i < size)
	{
		lst = lst->childs[state->puzzle[i / env->size][i % env->size]];
		if (!lst)
		{
			return (NULL);
		}
		++i;
	}
	if (is_closed)
		*is_closed = !lst->opened;
	return (lst->state);
}
