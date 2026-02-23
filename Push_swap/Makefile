# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jezambra <jezambra@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 17:47:17 by jezambra          #+#    #+#              #
#    Updated: 2026/02/23 22:45:05 by jezambra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN := \033[0;32m
RED := \033[31m

#name file
NAME = push_swap

#compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#files surce y objets
SRC =	push_swap_utils.c \
	

OBJ = $(SRC:.c=.o)

#comad for make library and delete files
AR = ar rcs
RM = rm -f

#everything after : its comand exclusive inside here
.PHONY: all clean fclean re

#rule that compiles everything
all: $(NAME)

#rule for make library
$(NAME): $(OBJ)
	$(AR) $@ $^
	@echo "${GREEN} $(NAME) Created."
#all file .c to .o
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

#rule for delete everything .o
clean:
	$(RM) $(OBJ)
	@echo "${RED} Deleted Objets."
	
#rule for delete everything .o and .a
fclean: clean
	$(RM) $(NAME)
	@echo "${RED} Deleted Library."
	
#rule for recompile everything
re: fclean all