/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_calc_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 21:40:49 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/05 21:41:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	state_calc_score(t_env *env, t_state *state)
{
	if (env->algo == 1)
		state->score = manhattan(env, state);
	else if (env->algo == 2)
		state->score = misplaced(env, state);
	else
		state->score = row_column(env, state);
}
