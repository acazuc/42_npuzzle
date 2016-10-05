#include "npuzzle.h"

void state_free(t_env *env, t_state *state)
{
	for (int y = 0; y < env->size; ++y)
	{
		free(state->puzzle[y]);
	}
	free(state->puzzle);
	free(state);
}
