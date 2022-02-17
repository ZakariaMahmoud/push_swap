# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmahmoud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:12:52 by zmahmoud          #+#    #+#              #
#    Updated: 2021/11/27 16:42:43 by zmahmoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =ft_isdigit.c\
	ft_putendl_fd.c\
	ft_striteri.c\
	ft_isprint.c\
	ft_putnbr_fd.c\
	ft_strjoin.c\
	ft_strrchr.c\
	ft_atoi.c\
	ft_itoa.c\
	ft_putstr_fd.c\
	ft_strlcat.c\
	ft_strtrim.c\
	ft_bzero.c\
	ft_memchr.c\
	ft_split.c\
	ft_strlcpy.c\
	ft_substr.c\
	ft_calloc.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_isalnum.c\
	ft_memcpy.c\
	ft_strmapi.c\
	ft_isalpha.c\
	ft_memset.c\
	ft_strchr.c\
	ft_strncmp.c\
	ft_tolower.c\
	ft_isascii.c\
	ft_putchar_fd.c\
	ft_strdup.c\
	ft_strnstr.c\
	ft_toupper.c\
	ft_memmove.c

BNS = ft_lstadd_back_bonus.c\
    ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c

FLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJS = $(subst .c,.o,$(SRCS))
OBJBNS = $(subst .c,.o,$(BNS))

all : $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) -c $(SRCS)
	ar -r $(NAME) $(OBJS)

bonus: $(OBJBNS)

$(OBJBNS) : $(BNS)
	gcc $(FLAGS) -c $(BNS)
	ar -r $(NAME) $(OBJBNS)

clean:
	rm -f $(OBJS) $(OBJBNS)

fclean: clean
	rm -f $(NAME)

re: fclean all
