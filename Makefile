# COLORS
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
RESET 	= 	\033[0m

# Flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
DEFAULT_GOAL	= all

# Folders
HEADERS_D		= ./headers/
SRCS_D			= ./srcs/
LIBFT_D			= ./libft/
OBJ_D			= ./objs/

# Files
NAME			= libftprintf.a
SRCS_F			= ft_printf.c ft_print_spec.c
#LIBFT_F			= ft_isdigit.c
OBJ_F			= $(SRCS_F:.c=.o) $(LIBFT_F:.c=.o)

SRCS			= $(addprefix $(SRCS_D), $(SRCS_F))
#LIBFT			= $(addprefix $(LIBFT_D), $(LIBFT_F))
OBJS			= $(addprefix $(OBJ_D), $(OBJ_F))
MMDS			= $(SRCS:.c=.d)
#include $(MMDS)

# Libs -lmlx -lm -lft 
LIBS			=  -L $(NAME)
INCLUDES		= -I $(HEADERS_D) -I $(LIBFT_D)

# COMMANDS		COMMANDS		COMMANDS

$(NAME):	$(OBJ_D) $(OBJS) Makefile
			@echo "$(RED)$(NAME): $(GREEN) Calling make in $(LIBFT_D) $(RESET)"
			@make -sC $(LIBFT_D) all
			@echo "$(NAME): $(GREEN) Creating $(NAME) $(RESET)"
#			$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(OBJS) -o $(NAME)
			@echo "$(RED)$(NAME): $(GREEN) >>>>>>>>>> DONE <<<<<<<<<< $(RESET)"
			ar rcs $(NAME) $(OBJS)

all: 		$(NAME)

include $(wildcard $(OBJ_D)%.d)
$(OBJ_D) :
				@mkdir -p $(OBJ_D)
				@echo "$(RED)$(NAME): $(GREEN)$(OBJ_D) was created$(RESET)"

$(OBJ_D)%.o :	$(SRCS_D)%.c
				$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@ -MMD

#$(LIBFT_D)%.c

#$(OBJ_):
#			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ -MMD
debug:		$(NAME)
			$(CC) $(CFLAGS) -L ./ $(INCLUDES) main.c -o debug.out
#			$(CC) -g -I $(HEADERS) $(SRCS) $(LIBFT) main.c -o debug.out






clean:
			@echo "$(NAME): $(BLUE) Calling clean in $(LIBFT_D) $(RESET)"
			@make -sC $(LIBFT_D) clean
			@echo "$(NAME): $(RED) Deleting $(OBJ_D) $(RESET)"
			@rm -rf $(OBJ_D)
			@echo "$(NAME): $(GREEN) clean: DONE $(RESET)"
fclean:	clean
			@echo "$(NAME): $(CYAN) Calling fclean in $(LIBFT_D) $(RESET)"
			@make -sC $(LIBFT_D) fclean
			@rm -f $(NAME) $(MMDS)
			@echo "$(NAME): $(GREEN) fclean: DONE $(RESET)"

re:		fclean all

.PHONY: all clean fclean re bonus

# rcs = runlib
