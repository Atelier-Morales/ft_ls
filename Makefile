# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/21 11:06:58 by fmorales          #+#    #+#              #
#    Updated: 2015/11/01 18:46:32 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
        display_dir_entries.c \
        sanitize_standard_input.c \
        check_errors.c \
        set_directory_structure.c \
        array_functions.c \
        iterative_display_mode.c \
        recursive_display_mode.c \
        list_functions.c \
        sort_list.c \
        display_total_blocks.c \
        get_links_len.c \
        get_dirs.c \
        get_entry_infos.c \
        set_sorting_rules.c

DIR = srcs/
LIB = libft/
HEADER = includes/
FLAGS = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)
NAME = ft_ls
TEST_FILE = test_ls.c

test_all: re clean_test test

test:
	gcc $(TEST_FILE) -o tests

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $^ -L$(LIB) -lft
	@echo "ft_ls is ready. Enjoy!"

%.o: $(DIR)%.c
	@gcc $(FLAGS)  -o $@ -c $< -I$(LIB)$(HEADER) -I$(HEADER)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(LIB)
	@echo "Objects deleted"

fclean: clean clean_test
	@rm -f $(NAME)
	@make fclean -s -C $(LIB)
	@echo "Folder cleanup successful"

clean_test:
	@rm -f tests
	@rm -f test/dest.txt
	@rm -f test/org.txt
	@rm -f test/diff

re: fclean all

.PHONY: all clean fclean re test test_all
