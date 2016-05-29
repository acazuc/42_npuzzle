#include "npuzzle.h"

t_state *state_new()
{
	t_state *state;

	if (!(state = malloc(sizeof(*state))))
	{
		ft_putendl_fd("npuzzle: failed to malloc new state", 2);
		exit(EXIT_FAILURE);
	}
	state->pred = NULL;
	state->g = 0;
	state->h = 0;
	return (state);
}
