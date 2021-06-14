NAME			= libftprintf.a

HEADERS			= ./headers/
NAMES			= ft_printf.c ft_print_spec.c
OBJS			= $(NAMES:.c=.o)

LIBFT_F			= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
					ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
					ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			 		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
LIBFT_D			= ./libft/
LIBFT			= $(addprefix $(LIBFT_D), $(LIBFT_F))
LIBFT_OBJ		= $(LIBFT:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I 

.DEFAULT_GOAL	= all

# COLORS
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
RESET 	= 	\033[0m

.c.o:
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o ${<:.c=.o} -MMD

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJ)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJ)

MMDS			= $(NAMES:.c=.d)
include $(MMDS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus