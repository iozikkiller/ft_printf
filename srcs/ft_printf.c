#include "../headers/ft_printf.h"

int	ft_getdigit(const char *f, int *length)
{
	int	i;

	i = 0;
	*length = 0;
	while (ft_isdigit(*(f + i)))
	{
		*length = (*length * 10) + (*(f + i) - '0');
		i++;
	}
	return (i);
}

int ft_charset(const char *f, char *spec)
{
	char	*set;
	
	set = _CHARSET;
	while (*set)
	{
		if (*set == *f)
		{
			*spec = *f;
			return (1);
		}
		set++;
	}
	return (0);
}

void	ft_print_spec(t_t t, va_list arg)
{
	if (t.spec == 'd' || t.spec == 'i')
		ft_print_d(t, va_arg(arg, int));
	else if (t.spec == 'c')
		ft_print_c(t, va_arg(arg, int));
		/*
	else if (t.spec == 'c')
		ft_print_c(t, arg);
	else if (t.spec == 's')
		ft_print_s(t, arg);
	else if (t.spec == 'p')
		ft_print_p(t, arg);
	else if (t.spec == 'u')
		ft_print_u(t, arg);
	else if (t.spec == 'x' || t.spec == 'X')
		ft_print_x(t, arg);
	else if (t.spec == '%')
		ft_print_it(t, arg);
		*/
}

int	ft_form(const char *f, va_list arg)
{
	int	i;
	t_t	t;

	i = 1;
	if (*(f + i) == '0' && ++i != 0)
		t.ljust = 0;
	while (*(f + i) == '-' && ++i != 0)
		t.ljust = -1;
	if (*(f + i) == '*' && i++ != 0)
		t.length = 0;
	else if (ft_isdigit(*(f + i)))
		i += ft_getdigit(f + i, &t.length);
	// else if (*(f + i) == '.' && *(f + i) != 0)
	while (*(f + i) == '.' && ++i != 0)
		if (*(f + i) == '*' && ++i != 0)
			t.precs = 0;
		else
			i += ft_getdigit(f + i, &t.precs);
	if (ft_charset(f + i, &t.spec))
		ft_print_spec(t, arg);
	else
		return (1);// (ft_printchar(*f)); //print and return 1;
	return (i);
}

int	ft_printf(const char *f, ...)
{
	va_list arg;
	//int		res;
	int	i;

	i = 0;
	va_start (arg, f);
	//res = ft_parse (f, arg);

	while (*(f + i) != '\0')
	{
		if (*(f + i) == '%')
			i += ft_form(f + i, arg);
		else
			write(1, &(*(f + i)), 1);//ft_putchar(*(f + i));
		i++;
	}

	va_end (arg);
	return (i);	
}

int main (void)
{ 
ft_printf ("2.1 Вывод числа 123 с форматом по умолчанию:\n");
{ int d1=123;
	ft_printf ("%d\n",d1);
}
}
