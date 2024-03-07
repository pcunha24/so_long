/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:47:17 by pedalexa          #+#    #+#             */
/*   Updated: 2024/01/25 22:39:48 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_img(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game ->mlx, game ->win, image, x * 32, y * 32);
}

static void	draw_player(t_game *game, int x, int y)
{
	game -> x_player = x;
	game -> y_player = y;
	draw_img(game, game -> img_player, x, y);
}

static void	draw_exit(t_game *game, int x, int y)
{
	char	*e_path;

	e_path = "textures/exit_open.xpm";
	if (game -> n_coll == 0)
	{
		draw_img(game, game -> img_exit, x, y);
		mlx_destroy_image(game -> mlx, game -> img_exit);
		game -> img_exit = mlx_xpm_file_to_image
			(game -> mlx, e_path, &game -> img_width, &game -> img_height);
		draw_img(game, game -> img_exit, x, y);
	}
	else
		draw_img(game, game -> img_exit, x, y);
}

static void	draw_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game ->map[y])
	{
		x = 0;
		while (game ->map[y][x])
		{
			if (game ->map[y][x] == '1')
				draw_img(game, game -> img_wall, x, y);
			else if (game ->map[y][x] == '0')
				draw_img(game, game -> img_floor, x, y);
			else if (game ->map[y][x] == 'P')
				draw_player(game, x, y);
			else if (game ->map[y][x] == 'C')
				draw_img(game, game -> img_coll, x, y);
			else if (game ->map[y][x] == 'E')
				draw_exit(game, x, y);
			x++;
		}
		y++;
	}
}

int	draw_map(t_game *game)
{
	if (game -> endgame)
	{
		ft_putstr_fd("Congratulations! You won!\n", 1);
		destroy_game(game);
		exit(0);
	}
	draw_images(game);
	return (0);
}
