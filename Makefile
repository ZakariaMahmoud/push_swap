SRCS =push_swap.c\
	./functions/ft_helper.c\
	./operations/operations_p.c\
	./operations/operations_r.c\
	./operations/operations_s.c\
	stack_helper.c

TEST =learn.c\
	./operations/operations_r.c\
	./operations/operations_s.c\
	./operations/operations_p.c\
	./functions/ft_helper.c\

	
LIBFT =libft/ft_atoi.c\
	libft/ft_isdigit.c\
	libft/ft_lstadd_back.c\
	libft/ft_lstadd_front.c\
	libft/ft_lstlast.c\
	libft/ft_lstnew.c\
	libft/ft_lstsize.c

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

