#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define _CHARSET "cspdiuxX%"

typedef struct s_s	t_t;
struct s_s
{
	int		ljust;	/* if '*' puting 0 at left to fit length, -1 justify  '-'*/
	int		length;	// '*'0 - read v_arg widt '*' or int or '.*'
	int		precs;

	int		sign;	/* + Forces to preceed with sign */
	//int		space;	/* ' ' - if '+' unused place space instead */
	//int		prpos;	/* print position */
	//int		radix;	// default radix 10
	char	spec;	//	cspdiuxX 
	// '-0.*'

};

int	ft_printf(const char *, ...);

#endif