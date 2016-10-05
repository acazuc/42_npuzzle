#include "npuzzle.h"

int main(int ac, char **av)
{
	t_env env;

	srand(epoch_millis());
	if (ac < 3)
	{
		ft_putendl_fd("npuzzle: usage:\nnpuzzle <--manhattan | --misplaced | --row_column> file\nnpuzzle <--manhattan | --misplaced | --row_column> --random size", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp(av[1], "--manhattan"))
		env.algo = 1;
	else if (!ft_strcmp(av[1], "--misplaced"))
		env.algo = 2;
	else if (!ft_strcmp(av[1], "--row_column"))
		env.algo = 3;
	else
	{
		ft_putendl_fd("npuzzle: invalid algorithm\nusage:\nnpuzzle <--manhattan | --misplaced | --row_column> file\nnpuzzle <--manhattan | --misplaced | --row_column> --random size>", 2);
		exit(EXIT_FAILURE);
	}
	env.start = state_new();
	if (!ft_strcmp(av[2], "--random"))
	{
		if (ac < 3)
		{
			ft_putendl_fd("npuzzle: usage:\nnpuzzle <--manhattan | --misplaced | --row_column> --random size", 2);
			exit(EXIT_FAILURE);
		}
		char *tmp = av[3];
		while (*tmp == '0')
			tmp++;
		if (!ft_strisdigit(av[3]) || ft_strlen(tmp) > 3 || (env.size = ft_atoi(tmp)) > 255 || env.size < 2)
		{
			ft_putendl_fd("npuzzle: invalid size, must be integer between 2 and 255\nusage:\nnpuzzle <--manhattan | --misplaced | --row_column> --random size", 2);
			exit(EXIT_FAILURE);
		}
		generate_random(&env);
	}
	else
	{
		parse_file(&env, av[2]);
	}
	ft_putendl("start:");
	dump_state(&env, env.start);
	env.end = state_new_size(&env);
	build_end(&env);
	state_calc_score(&env, env.end);
	state_calc_score(&env, env.start);
	ft_putendl("\nend:");
	dump_state(&env, env.end);
	ft_putchar('\n');
	if (is_solvable(&env))
	{
		long start = epoch_millis();
		astar(&env);
		printf("solve time: %ld ms\n", epoch_millis() - start);
	}
	else
	{
		ft_putendl("This puzzle is not solvable");
	}
	return (1);
	(void)av;
}
