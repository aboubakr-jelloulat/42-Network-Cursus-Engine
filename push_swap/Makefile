NAME         = push_swap
BONUS_NAME   = checker

CC           = cc
CFLAGS       = -Wall -Wextra -Werror
RM           = rm -f

HEADER       = ./includes/push_swap.h
BONUS_HEADER = ./includes/push_swap_bonus.h

LIBFT        = ./includes/libft/libft.a

SRCS         = 	src/push_swap/main.c  	src/push_swap/parsing.c  	 src/push_swap/stack_init.c  	src/push_swap/about_stack.c  src/push_swap/utils.c\
               	src/moves/push.c 		src/moves/reverse_rotate.c   src/moves/rotate.c 			src/moves/swap.c src/sorting/indexing.c\
              	src/sorting/algorithme.c 	src/sorting/sort_three.c 	 src/sorting/sort_four.c 		src/sorting/chunck.c src/sorting/sort_five.c
              	

BONUS        = 	bonus/get_next_line_bonus.c bonus/checker_bonus.c src/push_swap/parsing.c src/push_swap/stack_init.c src/push_swap/about_stack.c src/moves/push.c \
        		src/moves/reverse_rotate.c src/moves/rotate.c  src/moves/swap.c src/push_swap/utils.c

OBJ_SRCS     = $(SRCS:.c=.o)
OBJ_BONUS    = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SRCS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)


%.o: %.c $(HEADER) $(BONUS_HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@


$(LIBFT):
	@$(MAKE) -C ./includes/libft


clean:
	@$(MAKE) clean -C ./includes/libft
	@$(RM) $(OBJ_SRCS) $(OBJ_BONUS)

fclean: clean
	@$(MAKE) fclean -C ./includes/libft
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus 
