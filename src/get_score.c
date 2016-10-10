/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 01:17:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/10 18:44:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int	get_score(t_env *env, t_state *s1, t_state *s2)
{
	if (env->algo == 1)
		return (manhattan(env, s1, s2));
	else if (env->algo == 2)
		return (misplaced(env, s1, s2));
	else if (env->algo == 3)
		return (row_column(env, s1, s2));
	return (euclidian(env, s1, s2));
}
