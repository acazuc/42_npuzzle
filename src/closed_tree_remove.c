/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_tree_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 00:01:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/10 19:01:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	closed_tree_remove(t_env *env, t_closed_tree *tree, t_state *state)
{
	t_closed_tree *lst;
	int size = env->size * env->size;
	int i = 0;

	lst = tree;
	while (i < size)
	{
		lst = lst->childs[state->puzzle[i / env->size][i % env->size]];
		if (!lst)
		{
			ft_putendl("FAILED OMG");
			exit(EXIT_FAILURE);
			return ;
		}
		++i;
	}
	lst->state = NULL;
}
