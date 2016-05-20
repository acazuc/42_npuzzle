#include "npuzzle.h"

int valid_int(char *str)
{
	if (str[0] == '-')
	{
		if (ft_strlen(str) > 11)
			return (0);
	}
	else if (ft_strlen(str) > 10)
		return (0);
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}
