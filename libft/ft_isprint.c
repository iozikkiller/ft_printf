#include "libft.h"

int	ft_isprint (int ch)
{
	return (ch > 31 && ch < 127);
}
