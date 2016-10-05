#include "npuzzle.h"

static int manhattan_sub(t_env *env, t_state *state, int nb)
{
	int stateX = 0;
	int stateY = 0;
	int endX = 0;
	int endY = 0;

	for (stateY = 0; stateY < env->size; ++stateY)
	{
		for (stateX = 0; stateX < env->size; ++stateX)
		{
			if (state->puzzle[stateY][stateX] == nb)
				goto secondLoop;
		}
	}
secondLoop:
	for (endY = 0; endY < env->size; ++endY)
	{
		for (endX = 0; endX < env->size; ++endX)
		{
			if (env->end->puzzle[endY][endX] == nb)
				goto endReturn;
		}
	}
endReturn:
	return (abs(stateX - endX) + abs(stateY - endY));
}

int manhattan(t_env *env, t_state *state)
{
	int size = env->size * env->size;
	int total = 0;

	total = 0;
	for (int i = 1; i < size; ++i)
	{
		total += manhattan_sub(env, state, i);
	}
	return (total);
}
