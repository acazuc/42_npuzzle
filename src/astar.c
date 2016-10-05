#include "npuzzle.h"

void astar(t_env *env)
{
	t_state_list *opened = NULL;
	t_state_list *closed = NULL;
	t_state *best_state;
	t_state_list *expend;
	t_state_list *tmp;
	int complexity_time = 0;
	int complexity_size = 0;
	int success = 0;
	int size_tmp;

	state_list_push(&opened, env->start);
	if ((size_tmp = state_list_size(opened) + state_list_size(closed)) > complexity_size)
	{
		complexity_size = size_tmp;
	}
	while (opened && !success)
	{
		best_state = opened->state;
		complexity_time++;
		if (state_equals(env, best_state, env->end))
		{
			success = 1;
			break;
		}
		state_list_remove(&opened, best_state);
		state_list_push(&closed, best_state);
		expend = state_expend(env, best_state);
		if ((size_tmp = state_list_size(opened) + state_list_size(closed) + state_list_size(expend)) > complexity_size)
		{
			complexity_size = size_tmp;
		}
		while (expend)
		{
			if (!state_list_contains(env, opened, expend->state) && !state_list_contains(env, closed, expend->state))
			{
				state_list_push(&opened, expend->state);
				expend->state->pred = best_state;
				expend->state->g = best_state->g + 1;
			}
			else
			{
				if (expend->state->g + expend->state->score > best_state->g + expend->state->score)
				{
					expend->state->g = best_state->g + 1;
					expend->state->pred = best_state;
					if (state_list_contains(env, closed, expend->state))
					{
						state_list_remove(&closed, expend->state);
						state_list_push(&opened, expend->state);
					}
					else if (!state_list_contains(env, opened, expend->state))
					{
						free(expend->state);
					}
				}
			}
			tmp = expend;
			expend = expend->next;
			free(tmp);
		}
		state_list_free(expend);
	}
	if (success)
	{
		setvbuf(stdout, NULL, _IOFBF, BUFSIZ);
		printf("solution: ");
		print_solution(env, best_state);
		printf("time complexity: %d\nsize complexity: %d\nnumber of moves: %d\n", complexity_time, complexity_size, best_state->g);
		fflush(stdout);
		setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	}
	else
	{
		ft_putendl("This puzzle is not solvable");
	}
}
