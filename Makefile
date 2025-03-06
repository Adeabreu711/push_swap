# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 15:08:31 by alde-abr          #+#    #+#              #
#    Updated: 2025/03/06 16:38:40 by alde-abr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS =
LIB = libft/libft.a

SRC = \
	push_swap.c algo_sort.c algo_find_cheap.c algo_move.c \
	stack_utils1.c stack_utils2.c algo_utils.c ps_parsing.c \
	inst_push.c inst_swap.c inst_rotate.c inst_reverse_rotate.c \

SRC_BONUS = \
	checker.c checker_utils.c process_insts.c \
	stack_utils1.c stack_utils2.c algo_utils.c ps_parsing.c \
	inst_push.c inst_swap.c inst_rotate.c inst_reverse_rotate.c \

INCLUDES = -Iincludes/
INCLUDES_BONUS = -Ibonus/

SRC_DIR = src/
OBJ_DIR = obj/
BONUS_DIR = bonus/

all: $(NAME)

bonus: $(NAME_BONUS)

#Construction de la lib
$(LIB):
	make -C libft/

#Création des fichiers .o
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(SRC_BONUS:.c=.o))

#Création du dossier OBJ_DIR
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(INCLUDES_BONUS) $(CFLAGS) -c $< -o $@

#Création du programme
$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

$(NAME_BONUS): $(LIB) $(OBJ_DIR) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -Llibft -lft -o $(NAME_BONUS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C libft/

re: fclean all

.PHONY = all clean fclean re bonus
