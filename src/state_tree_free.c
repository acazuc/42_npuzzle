/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_tree_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 20:29:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/16 20:40:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void state_tree_free(t_env *env, t_state_tree *node)
{
	int size = env->size * env->size;
	int i = 0;

	while (i < size)
	{
		if (node->childs[i])
			state_tree_free(env, node->childs[i]);
		free(node->childs[i]);
		++i;
	}
	free(node->childs);
	if (node->state)
		state_free(env, node->state);
}
