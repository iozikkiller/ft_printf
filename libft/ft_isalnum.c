#include "libft.h"

int	ft_isalnum (int ch)
{
	if ((ch > 47 && ch < 58) || (ch > 64 && ch < 91) || (ch > 96 && ch < 123))
		return (1);
	return (0);
}
