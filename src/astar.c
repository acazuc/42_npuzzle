#include "npuzzle.h"

void astar(t_env *env)
{
	t_closed_tree closed;
	t_closed_tree opened_tree;
	t_state_list *opened = NULL;
	t_state *best_state;
	t_state_list *expend;
	t_state_list *tmp;
	t_state *tmp_nei;
	int in_closed;
	int complexity_time = 0;
	int complexity_size = 0;
	int success = 0;
	int size_tmp;
	int opened_size = 0;
	int closed_size = 0;
	int tmpg;

	ft_bzero(&closed, sizeof(closed));
	if (!(closed.childs = malloc(sizeof(*closed.childs) * env->size * env->size)))
	{
		ft_putendl_fd("nuzzle: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(closed.childs, sizeof(*closed.childs) * env->size * env->size);
	ft_bzero(&opened_tree, sizeof(opened_tree));
	if (!(opened_tree.childs = malloc(sizeof(*opened_tree.childs) * env->size * env->size)))
	{
		ft_putendl_fd("npuzzle: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(opened_tree.childs, sizeof(*opened_tree.childs) * env->size *env->size);
	state_list_push(&opened, env->start);
	closed_tree_push(env, &opened_tree, env->start);
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
		closed_tree_remove(env, &opened_tree, best_state);
		closed_tree_push(env, &closed, best_state);
		closed_size++;
		expend = state_expend(env, best_state);
		if ((size_tmp = opened_size + closed_size + state_list_size(expend)) > complexity_size)
		{
			complexity_size = size_tmp;
		}
		while (expend)
		{
			in_closed = closed_tree_get(env, &closed, expend->state) != NULL;
			if (in_closed)
			{
				tmp = expend;
				expend = expend->next;
				free(tmp);
				continue;
			}
			tmpg = best_state->g + 1;
			tmp_nei = closed_tree_get(env, &opened_tree, expend->state);
			if (!tmp_nei)
			{
				expend->state->pred = best_state;
				expend->state->g = tmpg;
				expend->state->f = expend->state->g + expend->state->h;
				state_list_push(&opened, expend->state);
				closed_tree_push(env, &opened_tree, expend->state);
				opened_size++;
			}
			else if (tmpg >= tmp_nei->g)
			{
				tmp = expend;
				expend = expend->next;
				free(tmp);
				continue;
			}
			else
			{
				tmp_nei->pred = best_state;
				tmp_nei->g = tmpg;
				tmp_nei->f = tmp_nei->g + tmp_nei->h;
			}
			tmp = expend;
			expend = expend->next;
			free(tmp);
		}
		state_list_free(expend);
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
		printf("solution: ");
		print_solution(env, best_state);
		printf("time complexity: %d\nsize complexity: %d\nnumber of moves: %d\n", complexity_time, complexity_size, i);
		fflush(stdout);
		setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	}
	else
	{
		ft_putendl("This puzzle is not solvable");
	}
}
