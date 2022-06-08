# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 11:17:30 by zmahmoud          #+#    #+#              #
#    Updated: 2022/06/08 11:17:55 by zmahmoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =functions/ft_checker.c\
	functions/positions.c\
	functions/sort_helper.c\
	functions/ft_helper.c\
	functions/sort.c\
	functions/stack_helper.c\
	functions/init.c\
	operations/operations_p.c\
	operations/operations_s.c\
	operations/operations_r.c\
	push_swap.c\
	
LIBFT =libft/ft_atoi.c\
	libft/ft_isdigit.c\
	libft/ft_lstadd_back.c\
	libft/ft_lstadd_front.c\
	libft/ft_lstlast.c\
	libft/ft_lstnew.c\
	libft/ft_strcmp.c\
	libft/ft_lstsize.c

BNS =functions/ft_checker.c\
	functions/ft_helper.c\
	bonus/get_next_line/get_next_line.c\
	bonus/get_next_line/get_next_line_utils.c\
	bonus/bonus_helper.c\
	operations/operations_p.c\
	operations/operations_s.c\
	operations/operations_r.c\
	operations/operations_rr.c\
	checker.c\

FLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAMEBNS = checker
OBJS = $(subst .c,.o,$(SRCS))
OBJSBNS = $(subst .c,.o,$(BNS))

all : $(NAME)

$(NAME): $(OBJS)
	gcc  $(SRCS) $(LIBFT) -o $(NAME)

bonus: $(OBJSBNS)
	gcc  $(BNS) $(LIBFT) -o $(NAMEBNS)

clean:
	rm -f $(OBJS) $(OBJSBNS)


fclean: clean
	rm -f $(NAME) $(NAMEBNS)

re: fclean all
