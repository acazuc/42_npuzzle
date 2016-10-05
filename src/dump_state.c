#include "npuzzle.h"

void dump_state(t_env *env, t_state *state)
{
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			printf("%d%c", state->puzzle[y][x], x == env->size - 1 ? '\n' : ' ');
		}
	}
}
