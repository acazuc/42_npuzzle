#include "npuzzle.h"

int state_equals(t_env *env, t_state *s1, t_state *s2)
{
	int x;
	int y;

	y = 0;
	while (y < env->size)
	{
		x = 0;
		while (x < env->size)
		{
			if (s1->puzzle[y][x] != s2->puzzle[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
