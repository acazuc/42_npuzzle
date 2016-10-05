#include "npuzzle.h"

int misplaced(t_env *env, t_state *state)
{
	int total;

	total = 0;
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			if (state->puzzle[y][x] != 0 && state->puzzle[y][x] != env->end->puzzle[y][x])
				++total;
		}
	}
	return (total);
}
