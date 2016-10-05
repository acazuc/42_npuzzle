#include "npuzzle.h"

void state_free(t_env *env, t_state *state)
{
	int y;

	y = 0;
	while (y < env->size)
	{
		free(state->puzzle[y]);
		y++;
	}
	free(state->puzzle);
	free(state);
}
