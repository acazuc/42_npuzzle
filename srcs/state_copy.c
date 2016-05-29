#include "npuzzle.h"

t_state *state_copy(t_env *env, t_state *from)
{
	t_state *state;
	int y;
	int x;

	state = state_new_size(env);
	y = 0;
	while (y < env->size)
	{
		x = 0;
		while (x < env->size)
		{
			state->puzzle[y][x] = from->puzzle[y][x];
			x++;
		}
		y++;
	}
	return (state);
}
