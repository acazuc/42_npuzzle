/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_calc_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 21:40:49 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/10 01:23:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	state_calc_score(t_env *env, t_state *state)
{
	state->h = get_score(env, state, env->end);
	state->f = state->g + state->h;
}
