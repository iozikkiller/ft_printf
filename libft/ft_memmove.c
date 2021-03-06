#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	if (dst > src)
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	else
	{
		while (len > i)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
