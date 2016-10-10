/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euclidian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:45:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/10 19:08:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void get_diff(t_env *env, t_state *state, int ax, int ay, int val, int *dx, int *dy)
{
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			if (state->puzzle[y][x] == val)
			{
				*dx += abs(x - ax);
				*dy += abs(y - ay);
				return;
			}
		}
	}
}

int euclidian(t_env *env, t_state *s1, t_state *s2)
{
	int dx = 0;
	int dy = 0;

	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			get_diff(env, s2, x, y, s1->puzzle[y][x], &dx, &dy);
		}
	}
	return (sqrt(dx * dx + dy * dy));
}
