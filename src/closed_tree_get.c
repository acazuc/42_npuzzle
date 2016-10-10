/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_tree_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 23:52:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/10 00:38:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state	*closed_tree_get(t_env *env, t_closed_tree *tree, t_state *state)
{
	t_closed_tree *lst;
	int size = env->size * env->size;
	int i = 0;

	lst = tree;
	while (i < size)
	{
		lst = lst->childs[state->puzzle[i / 3][i % 3]];
		if (!lst)
		{
			return (NULL);
		}
		++i;
	}
	return (lst->state);
}
