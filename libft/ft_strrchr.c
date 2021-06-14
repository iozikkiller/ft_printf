#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;

	r = 0;
	while (*s)
	{
		if (*s == c)
			r = (char *)s;
		s++;
	}
	if (r)
		return (r);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
