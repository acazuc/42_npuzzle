#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>

typedef struct s_state_list t_state_list;
typedef struct s_state t_state;
typedef struct s_env t_env;
typedef struct s_closed_tree t_closed_tree;

long epoch_millis(void);
char *get_next_line(int fd);
void parse_file(t_env *env, char *file);
int valid_int(char *str);
void dump_state(t_env *env, t_state *state);
void state_list_push(t_state_list **lst, t_state *state);
void state_list_remove(t_state_list **lst, t_state *state);
t_state_list *state_list_get(t_env *env, t_state_list *lst, t_state *state);
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
int manhattan(t_env *env, t_state *s1, t_state *s2);
void generate_random(t_env *env);
int is_solvable(t_env *env);
long epoch_millis(void);
void print_solution(t_env *env, t_state *state);
int state_list_size(t_state_list *lst);
int misplaced(t_env *env, t_state *s1, t_state *s2);
int row_column(t_env *env, t_state *s1, t_state *s2);
int get_score(t_env *env, t_state *s1, t_state *s2);
void state_calc_score(t_env *env, t_state *state);
int state_cost(t_state *old, t_state *new);
void closed_tree_push(t_env *env, t_closed_tree *tree, t_state *state);
t_state *closed_tree_get(t_env *env, t_closed_tree *tree, t_state *state);
void closed_tree_remove(t_env *env, t_closed_tree *tree, t_state *state);
int euclidian(t_env *env, t_state *s1, t_state *s2);

# define UNIFORM_COST 0

struct s_closed_tree
{
	t_state *state;
	t_closed_tree **childs;
};

struct s_env
{
	t_state *start;
	t_state *end;
	int uniform;
	int greedy;
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
	int f;
	int g;
	int h;
};

#endif
