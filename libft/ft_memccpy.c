#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int ch, size_t n)
{
	size_t		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)ch)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
