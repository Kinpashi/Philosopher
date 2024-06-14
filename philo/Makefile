# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 19:46:40 by aahlaqqa          #+#    #+#              #
#    Updated: 2024/06/06 16:12:07 by aahlaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS= -Wall -Wextra -Werror
LFLAGS= -lpthread
CC= cc
SOURCES= philo.c init_philo.c ft_atoi.c init_var.c ft_single_philo.c ft_philo.c ft_sleep.c ft_sleep_with_check.c check_command.c routine.c check_pos.c lock_func.c
OBJECTS= $(SOURCES:.c=.o)

NAME= philo

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS) -o $(NAME)

.c: .o
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

debug:
	cc $(CFLAGS) -g3 -fsanitize=thread $(SOURCES) -o philo

.PHONY: all clean fclean re
.SECONDARY: $(OBJECTS)