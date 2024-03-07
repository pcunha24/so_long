/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:47:29 by pedalexa          #+#    #+#             */
/*   Updated: 2024/01/25 16:31:59 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_images(t_game *game)
{
	char	*coll_path;
	char	*player_path;
	char	*exit_path;
	char	*wall_path;
	char	*floor_path;

	coll_path = "textures/coll.xpm";
	player_path = "textures/player.xpm";
	exit_path = "textures/exit_closed.xpm";
	wall_path = "textures/wall.xpm";
	floor_path = "textures/floor.xpm";
	game -> img_coll = mlx_xpm_file_to_image
		(game -> mlx, coll_path, &game -> img_width, &game -> img_height);
	game -> img_player = mlx_xpm_file_to_image
		(game -> mlx, player_path, &game -> img_width, &game -> img_height);
	game -> img_floor = mlx_xpm_file_to_image
		(game -> mlx, floor_path, &game -> img_width, &game -> img_height);
	game -> img_wall = mlx_xpm_file_to_image
		(game -> mlx, wall_path, &game -> img_width, &game -> img_height);
	game -> img_exit = mlx_xpm_file_to_image
		(game -> mlx, exit_path, &game -> img_width, &game -> img_height);
}

void	game_init(t_game *game)
{
	game -> mlx = mlx_init();
	game -> win = mlx_new_window
		(game -> mlx, game -> win_width, game -> win_height, "so_long");
	game -> n_moves = 0;
	game -> endgame = 0;
	get_images(game);
	draw_map(game);
}
