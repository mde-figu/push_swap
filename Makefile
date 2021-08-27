# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 14:48:36 by mde-figu          #+#    #+#              #
#    Updated: 2021/08/06 12:39:44 by mde-figu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES		= utils.c testargs.c load_list.c

SRCS_PATH	= srcs/

LIBFT_PATH	= ./libft

GNL_PATH	= ./get_next_line

SRCS		= $(addprefix $(SRCS_PATH), $(FILES)) main.c

OBJS		= ${SRCS:.c=.o}

INCLUDE		= -I./include

NAME		= push_swap

LIBFT_NAME	= libft.a

GNL_NAME	= get_next_line.a

LIBFT		= $(LIBFT_PATH)/$(LIBFT_NAME)

GNL			= $(GNL_PATH)/$(GNL_NAME)

COMP		= clang

AR			= ar -rcs

FLAGS		= -Wall -Wextra -Werror -v

.c.o:		
			${COMP} ${FLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@make -C $(GNL_PATH)
			@make -C $(LIBFT_PATH)
#			${COMP} ${FLAGS} -fsanitize=address -fsanitize=leak -g -o ${NAME} ${OBJS} $(LIBFT) $(GNL)
			${COMP} ${FLAGS} -g -o ${NAME} ${OBJS} $(LIBFT) $(GNL)

all:		${NAME}



clean:
			@rm -f ${OBJS}
			@make clean -C $(LIBFT_PATH)
			@make clean -C $(GNL_PATH)

fclean:		clean
			@rm -f ${NAME}
			@rm -f $(LIBFT_PATH)/*.a
			@rm -f $(GNL_PATH)/*.a
			@rm -f *.o
			
re:			fclean all

.PHONY:		all clean fclean re