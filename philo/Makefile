# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 16:53:22 by kyusulee          #+#    #+#              #
#    Updated: 2024/02/11 19:59:18 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS_DIR	= ./src/
INCL_DIR	= ./include/

HEAD	= $(INCL_DIR)philo.h
SRCS	= $(SRCS_DIR)main.c
OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAG	= -Wall -Wextra -Werror

ECHO	= echo
PRINTF	= printf
RM		= rm -f

all		:
			@$(MAKE) $(NAME)
			@$(ECHO) "$(CYAN) *** Make <$(NAME)> complete.$(DEFAULT)"

$(NAME)	:	$(OBJS) $(HEAD)
			@$(PRINTF) " 100%% compiling complete.$(DEFAULT)\n"
			@$(CC) $(CFLAG) -I$(INCL_DIR) $(OBJS) -o $(NAME)
			@$(ECHO) "$(CYAN) *** Linking complete.$(DEFAULT)"

clean	:
			@$(RM) $(OBJS)
			@$(ECHO) "$(YELLOW) *** Clean <$(NAME)> complete.$(DEFAULT)"

fclean	:
			@$(RM) $(OBJS)
			@$(RM) $(NAME)
			@$(ECHO) "$(RED) *** Fclean <$(NAME)> complete.$(DEFAULT)"

re		:
			@$(ECHO) " *** Re-make <$(NAME)> start."
			@$(MAKE) fclean
			@$(MAKE) all
			@$(ECHO) " *** Re-make <$(NAME)> complete."

%.o		:	%.c
			@$(PRINTF) "$(GREEN)#"
			@$(CC) $(CFLAG) -I$(INCL_DIR) -c $^ -o $@

.PHONY	:	all clean fclean re

RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
CYAN		=	\033[0;36m
DEFAULT		=	\033[0m
