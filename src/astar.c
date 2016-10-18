#include "npuzzle.h"

void astar(t_env *env)
{
	t_state_tree state_tree;
	t_state_list *opened = NULL;
	t_state *best_state;
	t_state_list *expend;
	t_state_list *tmp;
	t_state *tmp_state;
	int in_closed;
	int complexity_time = 0;
	int complexity_size = 0;
	int success = 0;
	int size_tmp;
	int opened_size = 0;
	int closed_size = 0;
	int tmpg;
	int is_closed = 0;

	memset(&state_tree, 0, sizeof(state_tree));
	if (!(state_tree.childs = malloc(sizeof(*state_tree.childs) * env->size * env->size)))
	{
		ft_putendl_fd("nuzzle: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	memset(state_tree.childs, 0, sizeof(*state_tree.childs) * env->size * env->size);
	state_list_push(&opened, env->start);
	state_tree_push(env, &state_tree, env->start, 1);
	if ((size_tmp = opened_size + closed_size) > complexity_size)
	{
		complexity_size = size_tmp;
	}
	while (opened)
	{
		best_state = opened->state;
		complexity_time++;
		if (best_state->h == 0)
		{
			success = 1;
			break;
		}
		tmp = opened;
		opened = opened->next;
		free(tmp);
		opened_size--;
		closed_size++;
		state_tree_set(env, &state_tree, best_state, 0);
		expend = state_expend(env, best_state);
		if ((size_tmp = opened_size + closed_size + state_list_size(expend)) > complexity_size)
		{
			complexity_size = size_tmp;
		}
		while (expend)
		{
			tmp_state = state_tree_get(env, &state_tree, expend->state, &is_closed);
			in_closed = tmp_state != NULL && is_closed;
			if (in_closed)
			{
				tmp = expend;
				expend = expend->next;
				state_free(env, tmp->state);
				free(tmp);
				continue;
			}
			tmpg = best_state->g + 1;
			if (!tmp_state)
			{
				expend->state->pred = best_state;
				expend->state->g = tmpg;
				expend->state->f = 0;
				if (!env->greedy)
					expend->state->f += expend->state->g;
				if (!env->uniform)
					expend->state->f += expend->state->h;
				state_list_push(&opened, expend->state);
				state_tree_push(env, &state_tree, expend->state, 1);
				opened_size++;
				tmp = expend;
				expend = expend->next;
				free(tmp);
				continue;
			}
			else if (tmpg >= tmp_state->g)
			{
				tmp = expend;
				expend = expend->next;
				state_free(env,tmp->state);
				free(tmp);
				continue;
			}
			tmp_state->pred = best_state;
			tmp_state->g = tmpg;
			tmp_state->f = 0;
			if (!env->greedy)
				tmp_state->f += tmp_state->g;
			if (!env->uniform)
				tmp_state->f += tmp_state->h;
			tmp = expend;
			expend = expend->next;
			state_free(env, tmp->state);
			free(tmp);
		}
	}
	if (success)
	{
		t_state *kek = best_state;
		int i = 0;
		while (kek)
		{
			++i;
			kek = kek->pred;
		}
		setvbuf(stdout, NULL, _IOFBF, BUFSIZ);
		printf("solution: \n");
		print_solution(env, best_state);
		printf("time complexity: %d\nsize complexity: %d\nnumber of moves: %d\n", complexity_time, complexity_size, i);
		fflush(stdout);
		setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	}
	else
	{
		ft_putendl("This puzzle is not solvable");
	}
	state_tree_free(env, &state_tree);
	state_list_free(opened);
}
