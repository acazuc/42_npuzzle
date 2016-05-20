#include "npuzzle.h"

int main(int ac, char **av)
{
	t_env env;

	if (ac < 2)
	{
		ft_putendl_fd("npuzzle: usage: npuzzle <puzzle file name>", 2);
		exit(EXIT_FAILURE);
	}
	parse_file(&env, av[1]);
	dump_puzzle(&env, env.puzzle);
	return (1);
}
