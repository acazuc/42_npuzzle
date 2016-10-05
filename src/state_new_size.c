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
	for (int i = 0; i < env->size; ++i)
	{
		if (!(state->puzzle[i] = malloc(sizeof(*state->puzzle[i]) * env->size)))
		{
			ft_putendl_fd("npuzzle: failed to malloc new state puzzle", 2);
			exit(EXIT_FAILURE);
		}
		for (int j = 0; j < env->size; ++j)
		{
			state->puzzle[i][j] = 0;
		}
	}
	return (state);
}
