#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	l2;

	if (!*s2)
		return ((char *)s1);
	l2 = ft_strlen(s2);
	while (*s1 != '\0' && l2 <= n--)
	{
		if (ft_memcmp(s1, s2, l2) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
