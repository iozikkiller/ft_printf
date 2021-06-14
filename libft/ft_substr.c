#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	min;

	if (!s || len < 1 || start >= ft_strlen(s))
		return (ft_strdup(""));
	min = ft_strlen(s + start);
	if (min > len)
		min = len;
	new = malloc(sizeof(char) * (min + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, (s + start), min + 1);
	return (new);
}
