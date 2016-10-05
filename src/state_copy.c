#include "npuzzle.h"

t_state *state_copy(t_env *env, t_state *from)
{
	t_state *state;

	state = state_new_size(env);
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			state->puzzle[y][x] = from->puzzle[y][x];
		}
	}
	state->score = from->score;
	return (state);
}
