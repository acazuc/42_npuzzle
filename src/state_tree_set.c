/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_tree_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 00:01:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 11:25:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	state_tree_set(t_env *env, t_state_tree *tree, t_state *state, int opened)
{
	t_state_tree *lst;
	int size = env->size * env->size;
	int i = 0;

	lst = tree;
	while (i < size)
	{
		lst = lst->childs[state->puzzle[i / env->size][i % env->size]];
		if (!lst)
			return ;
		++i;
	}
	lst->opened = opened;
}
