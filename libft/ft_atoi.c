#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	int		n;

	i = 0;
	s = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'\
		| str[i] == '\t' || str[i] == '\v')
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while ((str[i] - '0') >= 0 && (str[i] - '0') <= 9)
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (s * n);
}
