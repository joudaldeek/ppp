
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static int	words(char const *s, char c)
{
	int	count;
	int	in;

	count = 0;
	in = 0;
	while (*s)
	{
		if (*s != c && in == 0)
		{
			in = 1;
			count++;
		}
		if (*s == c)
			in = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(char const *s, int start, int end)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (start < end)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

static void	free_split(char **p, int i)
{
	while (i--)
		free(p[i]);
	free(p);
}

static int	fill_split(char **p, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			start = j;
			while (s[j] && s[j] != c)
				j++;
			p[i] = word_dup(s, start, j);
			if (!p[i])
				return (free_split(p, i), 0);
			i++;
		}
		else
			j++;
	}
	p[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!p)
		return (NULL);
	if (!fill_split(p, s, c))
		return (NULL);
	return (p);
}
