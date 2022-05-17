SRCS =push_swap.c\
	operations.c\
	stack_helper.c
	
LIBFT =libft/ft_atoi.c\
	./libft/ft_isdigit.c

FLAGS = -Wall -Wextra -Werror
NAME = push_swap
OBJS = $(subst .c,.o,$(SRCS))

all : $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)


clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all

