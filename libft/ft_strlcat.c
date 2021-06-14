#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;
	size_t	res;

	dstl = 0;
	srcl = 0;
	res = 0;
	while (dst[dstl])
		dstl++;
	while (src[res])
		res++;
	if (dstsize <= dstl)
		res += dstsize;
	else
		res += dstl;
	while (dstsize > dstl + 1 && src[srcl])
	{
		dst[dstl] = src[srcl];
		dstl++;
		srcl++;
	}
	dst[dstl] = '\0';
	return (res);
}
