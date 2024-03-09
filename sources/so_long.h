/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:47:54 by pedalexa          #+#    #+#             */
/*   Updated: 2024/03/09 15:16:57 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx/mlx.h"
# include "../libraries/minilibx/mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libraries/Libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_floor;
	void	*img_wall;
	void	*img_coll;
	void	*img_player;
	void	*img_exit;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		map_width;
	int		map_height;
	int		n_coll;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
	int		n_moves;
	int		endgame;
}	t_game;

# define KEY_ESC 65307

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

char	**read_map(char *path);
void	game_init(t_game *game);
int		draw_map(t_game *game);
void	gameplay(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		destroy_game(t_game *game);
void	free_map(char **map);
int		map_isvalid(t_game *game);
int		is_ber(char *map_file);
void	free_map(char **map);
int		path_check(t_game *game, char *path);
void	error_messages(char *message);
void	print_moves(t_game *game);

#endif
