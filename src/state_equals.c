#include "npuzzle.h"

int state_equals(t_env *env, t_state *s1, t_state *s2)
{
	if (s1->score != s2->score)
		return (0);
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			if (s1->puzzle[y][x] != s2->puzzle[y][x])
				return (0);
		}
	}
	return (1);
}
