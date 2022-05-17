SRCS =push_swap.c\
	operations.c

FLAGS = -Wall -Wextra -Werror
NAME = push_swap.a
OBJS = $(subst .c,.o,$(SRCS))

all : $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) -c $(SRCS)
	ar -r $(NAME) $(OBJS)
	cd libft	&& $(MAKE)


clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all
