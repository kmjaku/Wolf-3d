# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 18:26:16 by kmjaku            #+#    #+#              #
#    Updated: 2017/05/25 00:13:29 by kmjaku           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= wolf3d

FLAGS= -Wall -Werror -Wextra

FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT= ./libft/libft.a

SRCS= srcs/hook_textured.c \
	  srcs/hook_untextured.c \
	  srcs/hook_untextured_textured.c \
	  srcs/init.c \
	  srcs/main.c \
	  srcs/set_pixel.c \
	  srcs/textured.c \
	  srcs/textured_draw.c \
	  srcs/textured_next.c \
	  srcs/untextured.c \
	  srcs/untextured_next.c \
	  srcs/untextured_draw.c \
	  srcs/utils.c \

OBJ= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@echo "\nexecutable wolf3d is ready"
	@make -C LIBFT
	@gcc -o $(NAME) $(OBJ) $(LIBFT) $(FLAGS) $(FLAGS_MLX)

all: $(NAME)

clean:
	@echo "\nremoving all extensions '.o' in srcs/"
	@rm -rf $(OBJ)
	@echo "clean done for wolf3d"

fclean: clean
	@echo "\nremoving wolf3d"
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "fclean is done"

re:
	@echo "removing executable wolf3d"
	$(clean)
	@make -C libft/ re
	@echo "re-executing all"
	$(all)

.PHONY: clean fclean
