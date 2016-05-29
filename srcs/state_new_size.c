#include "npuzzle.h"

t_state *state_new_size(t_env *env)
{
	t_state *state;

	state = state_new();
	if (!(state->puzzle = malloc(sizeof(*state->puzzle) * env->size)))
	{
		ft_putendl_fd("npuzzle: failed to malloc new state puzzle", 2);
		exit(EXIT_FAILURE);
	}
	int i = 0;
	while (i < env->size)
	{
		if (!(state->puzzle[i] = malloc(sizeof(*state->puzzle[i]) * env->size)))
		{
			ft_putendl_fd("npuzzle: failed to malloc new state puzzle", 2);
			exit(EXIT_FAILURE);
		}
		int j = 0;
		while (j < env->size)
		{
			state->puzzle[i][j] = 0;
			j++;
		}
		i++;
	}
	return (state);
}
