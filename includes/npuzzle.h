#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <fcntl.h>

typedef struct s_env t_env;

char *get_next_line(int fd);
void parse_file(t_env *env, char *file);
int valid_int(char *str);
void dump_puzzle(t_env *env, int **puzzle);

struct s_env
{
	int **puzzle;
	int size;
};

#endif
