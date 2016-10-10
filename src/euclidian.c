/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euclidian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:45:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/10 21:34:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void get_diff(t_env *env, t_state *state, int ax, int ay, int val, double *dx, int *dy)
{
	(void)dy;
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			if (state->puzzle[y][x] == val)
			{
				*dx += sqrt(pow(abs(x - ax), 2) + pow(abs(y - ay), 2));
				return;
			}
		}
	}
}

int euclidian(t_env *env, t_state *s1, t_state *s2)
{
	double dx = 0;
	int dy = 0;

	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			get_diff(env, s2, x, y, s1->puzzle[y][x], &dx, &dy);
		}
	}
	return (dx);
}
