/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:47:13 by pedalexa          #+#    #+#             */
/*   Updated: 2024/03/06 13:43:06 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	destroy_game(t_game *game)
{
	if (game != 0)
	{
		if (game -> map != 0)
			free_map(game -> map);
		if (game -> img_player != 0)
			mlx_destroy_image(game -> mlx, game -> img_player);
		if (game -> img_exit != 0)
			mlx_destroy_image(game -> mlx, game -> img_exit);
		if (game -> img_coll != 0)
			mlx_destroy_image(game -> mlx, game -> img_coll);
		if (game -> img_wall != 0)
			mlx_destroy_image(game -> mlx, game -> img_wall);
		if (game -> img_floor != 0)
			mlx_destroy_image(game -> mlx, game -> img_floor);
		if (game -> win != 0)
			mlx_destroy_window(game -> mlx, game -> win);
		if (game -> mlx != 0)
			mlx_destroy_display(game -> mlx);
		free(game -> mlx);
	}
	exit(0);
}
