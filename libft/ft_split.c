#include "libft.h"

static size_t	ft_nword(char const *s, char c)
{
	size_t	res;
	size_t	subs;

	res = 0;
	subs = 0;
	while (*s)
	{
		if (*s == c && subs == 1)
			subs = 0;
		if (*s != c && subs == 0)
		{
			res++;
			subs = 1;
		}
		s++;
	}
	return (res);
}

static size_t	ft_strlen_c(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static void	*ft_free(char **res)
{
	size_t	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	n;

	if (!s)
		return (NULL);
	i = 0;
	n = ft_nword(s, c);
	res = malloc(sizeof(char *) * (n + 1));
	if (!res)
		return (NULL);
	while (n--)
	{
		while (*s == c)
			s++;
		res[i] = ft_substr(s, 0, ft_strlen_c(s, c));
		if (!res[i])
			return (ft_free(res));
		s += ft_strlen_c(s, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}
