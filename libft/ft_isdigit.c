#include "libft.h"

int	ft_isdigit (int ch)
{
	if (ch > 47 && ch < 58)
		return (1);
	return (0);
}
