# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahlaqqa <aahlaqqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 16:06:40 by aahlaqqa          #+#    #+#              #
#    Updated: 2024/06/14 23:49:53 by aahlaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS= -Wall -Wextra -Werror
LFLAGS= -lpthread
CC= cc
SOURCES= main.c check_command.c ft_atoi_bonus.c create_semaphore.c print_status.c philo_start.c exit_philo.c init_philo.c ft_sleep.c
OBJECTS= $(SOURCES:.c=.o)

NAME= philo_bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS) -o $(NAME)

.c: .o
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

debug:
	cc $(CFLAGS) -g3 -fsanitize=thread $(SOURCES) -o philo_bonus

.PHONY: all clean fclean re
.SECONDARY: $(OBJECTS)

