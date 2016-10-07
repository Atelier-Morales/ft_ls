#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:45:43 by fmorales          #+#    #+#              #
#    Updated: 2014/05/10 19:05:15 by fmorales         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC =	ft_strtabdup.c \
		ft_lstdelone.c \
		ft_lstnew.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isalpha.c \
		ft_atoi.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_strstr.c \
		ft_strrchr.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strncat.c \
		ft_strcat.c \
		ft_strncpy.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_memccpy.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_memset.c \
		ft_strlen.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_strdel.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_str_isint.c \
		ft_tabcount.c \
		ft_strcdup.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
