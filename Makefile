# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 18:55:33 by bfernan2          #+#    #+#              #
#    Updated: 2026/04/13 20:38:02 by bfernan2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = philo
CC      = gcc
CFLAGS  = -Werror -Wall -Wextra -pthread

SRC =   main.c utils.c parse.c 

OBJS = $(SRC:.c=.o)
INC = -I ./includes/

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@echo "  CC  $<"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "  LD  $(NAME)"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
