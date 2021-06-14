#include "libft.h"

static void	rec_n(long n, int fd)
{
	char	c;

	if (n > 9)
		rec_n(n / 10, fd);
	c = '0' + (n % 10);
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long	n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		rec_n(n, fd);
}
