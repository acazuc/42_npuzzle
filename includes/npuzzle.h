#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

# include <stdio.h>

typedef struct s_state_list t_state_list;
typedef struct s_state t_state;
typedef struct s_env t_env;

char *get_next_line(int fd);
void parse_file(t_env *env, char *file);
int valid_int(char *str);
void dump_state(t_env *env, t_state *state);
void state_list_push(t_state_list **lst, t_state *state);
void state_list_remove(t_state_list **lst, t_state *state);
void astar(t_env *env);
t_state *state_new();
void build_end(t_env *env);
t_state *state_new_size(t_env *env);
int state_equals(t_env *env, t_state *s1, t_state *s2);
int state_list_contains(t_env *env, t_state_list *lst, t_state *state);
void state_list_free(t_state_list *lst);
void state_free(t_env *env, t_state *state);
t_state_list *state_expend(t_env *env, t_state *state);
t_state *state_copy(t_env *env, t_state *from);
int manhattan(t_env *env, t_state *state);
void generate_random(t_env *env);
int is_solvable(t_env *env);
long epoch_millis(void);
void print_solution(t_env *env, t_state *state);
int state_list_size(t_state_list *lst);
int misplaced(t_env *env, t_state *state);
int row_column(t_env *env, t_state *state);

struct s_env
{
	t_state *start;
	t_state *end;
	int size;
	int algo;
};

struct s_state_list
{
	t_state *state;
	t_state_list *next;
};

struct s_state
{
	t_state *pred;
	int **puzzle;
	int g;
	int h;
};

#endif
