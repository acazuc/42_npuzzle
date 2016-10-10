#include "npuzzle.h"

static void print_usage()
{
	fprintf(stderr, "usage:\n");
	fprintf(stderr, "npuzzle <--manhattan | --misplaced | --row_column | --euclidian> [-g | -u] file\n");
	fprintf(stderr, "npuzzle <--manhattan | --misplaced | --row_column | --euclidian> [-g | -u] --random 3\n");
}

int main(int ac, char **av)
{
	t_env env;
	int i = 1;

	memset(&env, 0, sizeof(env));
	srand(epoch_millis());
	if (ac < 3)
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	if (!strcmp(av[i], "--manhattan"))
		env.algo = 1;
	else if (!strcmp(av[i], "--misplaced"))
		env.algo = 2;
	else if (!strcmp(av[i], "--row_column"))
		env.algo = 3;
	else if (!strcmp(av[i], "--euclidian"))
		env.algo = 4;
	else
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	env.start = state_new();
	++i;
	if (!strcmp(av[i], "-g"))
	{
		++i;
		env.greedy = 1;
	}
	else if (!strcmp(av[i], "-u"))
	{
		++i;
		env.uniform = 1;
	}
	if (!strcmp(av[i], "--random"))
	{
		if (ac < 3)
		{
			print_usage();
			exit(EXIT_FAILURE);
		}
		++i;
		char *tmp = av[i];
		while (*tmp == '0')
			tmp++;
		int k = 0;
		while (tmp[k])
			if (!isdigit(tmp[k++]))
			{
				fprintf(stderr, "npuzzle: invalid size\n");
				print_usage();
				exit(EXIT_FAILURE);
			}
		if (strlen(tmp) > 3 || (env.size = atoi(tmp)) > 255 || env.size < 2)
		{
			fprintf(stderr, "npuzzle: invalid size, must be integer between 2 and 255\n");
			print_usage();
			exit(EXIT_FAILURE);
		}
		generate_random(&env);
	}
	else
	{
		parse_file(&env, av[++i]);
		if (env.size < 2 || env.size > 255)
		{
			fprintf(stderr, "npuzzle: invalid size, must be integer between 2 and 255\n");
			print_usage();
			exit(EXIT_FAILURE);
		}
	}
	if (av[++i])
	{
		fprintf(stderr, "npuzzle: too much parameters\n");
		print_usage();
		exit(EXIT_FAILURE);
	}
	printf("start:\n");
	dump_state(&env, env.start);
	env.end = state_new_size(&env);
	build_end(&env);
	state_calc_score(&env, env.end);
	state_calc_score(&env, env.start);
	printf("\nend:\n");
	dump_state(&env, env.end);
	printf("\n");
	if (is_solvable(&env))
	{
		long start = epoch_millis();
		astar(&env);
		printf("solve time: %ld ms\n", epoch_millis() - start);
	}
	else
	{
		printf("This puzzle is not solvable\n");
	}
	return (1);
	(void)av;
}
