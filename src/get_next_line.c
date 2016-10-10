#include "npuzzle.h"

char *get_next_line(int fd)
{
	ssize_t readed;
	char *result;
	char *buff;

	if (!(buff = malloc(sizeof(*buff) * 2)))
	{
		fprintf(stderr, "npuzzle: can't malloc");
		exit(EXIT_FAILURE);
	}
	memset(buff, 0, 2);
	if (!(result = malloc(sizeof(*result))))
	{
		fprintf(stderr, "npuzzle: can't malloc");
		exit(EXIT_FAILURE);
	}
	memset(result, 0, 1);
	while ((readed = read(fd, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			return (result);
		if (!(result = ft_strjoin_free1(result, buff)))
		{
			fprintf(stderr, "npuzzle: can't malloc");
			exit(EXIT_FAILURE);
		}
	}
	if (readed == -1)
	{
		fprintf(stderr, "npuzzle: error while reading puzzle file");
		exit(EXIT_FAILURE);
	}
	return (result);
}
