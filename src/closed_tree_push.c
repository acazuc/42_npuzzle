/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_tree_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 23:45:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/10 00:53:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	closed_tree_push(t_env *env, t_closed_tree *tree, t_state *state)
{
	t_closed_tree *lst;
	t_closed_tree *new;
	int size = env->size * env->size;
	int i;

	i = 0;
	lst = tree;
	while (i < size)
	{
		int nb = state->puzzle[i / 3][i % 3];
		if (lst->childs[nb])
		{
			lst = lst->childs[nb];
			++i;
			continue;
		}
		if (!(new = malloc(sizeof(*new))))
		{
			ft_putendl_fd("npuzzle: malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		ft_bzero(new, sizeof(*new));
		if (!(new->childs = malloc(sizeof(*new->childs) * size)))
		{
			ft_putendl_fd("npuzzle: malloc failed", 2);
			exit(EXIT_FAILURE);
		}
		ft_bzero(new->childs, sizeof(*new->childs) * size);
		lst->childs[nb] = new;
		lst = new;
		++i;
	}
	lst->state = state;
}
