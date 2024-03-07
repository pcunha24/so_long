# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 19:30:11 by pedalexa          #+#    #+#              #
#    Updated: 2024/03/06 14:17:00 by pedalexa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				=	cc
RM				=	rm -f
LIBFT_PATH		=	./libraries/Libft
LIBFT			=	$(LIBFT_PATH)/libft.a
MINILIBX_PATH	=	./libraries/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
SOURCES			=	./sources/so_long.c ./sources/read_map.c ./sources/game_init.c ./sources/draw_map.c ./sources/gameplay.c ./sources/update_movement.c ./sources/destroy_game.c ./sources/map_isvalid.c ./sources/flood_fill.c
OBJECTS			= 	$(SOURCES:.c=.o)
NAME			=	so_long
CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:		fclean all

.PHONY:			all clean fclean re libft minilibx
