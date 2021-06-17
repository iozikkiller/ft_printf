#include "ft_printf.h"

void	ft_print_s(t_t t, int i)
{
	t.length = i;
	write(1, &t.spec, 1);
}
void	ft_print_c(t_t t, char c)
{
	if (t.ljust >= 0)
	{
		write(1, &c, 1);
		while (t.length-- > 1)
			write(1, " ", 1);
	}
	else if (t.ljust < 0)
	{
		while (t.length-- > 1)
			write(1, " ", 1);			
		write(1, &c, 1);
	}
}
/*
void	ft_print_s(t_t t, va_list arg)
	{
		
	}

void	ft_print_p(t_t t, va_list arg)
	{
		
	}

void	ft_print_u(t_t t, va_list arg)
	{
		
	}

void	ft_print_x(t_t t, va_list arg)
	{
		
	}

void	ft_print_it(t_t t, va_list arg)
	{
		
	}

*/