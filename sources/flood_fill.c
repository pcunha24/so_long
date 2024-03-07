/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:39:59 by pedalexa          #+#    #+#             */
/*   Updated: 2024/03/06 13:44:44 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_game *game, char **map_temp, int x, int y)
{
	if (x < 0 || x >= game -> map_width || y < 0 || y >= game -> map_height
		|| map_temp[y][x] == '1' || game -> map[y][x] == '1')
		return ;
	map_temp[y][x] = '1';
	if (game -> map[y][x] == 'E')
		return ;
	flood_fill(game, map_temp, x + 1, y);
	flood_fill(game, map_temp, x, y + 1);
	flood_fill(game, map_temp, x - 1, y);
	flood_fill(game, map_temp, x, y - 1);
}

static int	fill_map(t_game *game, char **map_temp)
{
	int	x;
	int	y;

	y = 0;
	while (map_temp[y])
	{
		x = 0;
		while (map_temp[y][x])
		{
			if (map_temp[y][x] == 'P')
			{
				game -> x_player = x;
				game -> y_player = y;
			}
			if (map_temp[y][x] == 'E')
			{
				game -> x_exit = x;
				game -> y_exit = y;
			}
			map_temp[y][x] = '0';
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_coll_path(t_game	*game, char	**map_temp)
{
	int	x;
	int	y;

	x = game -> x_exit;
	y = game -> y_exit;
	fill_map(game, map_temp);
	game -> map[y][x] = '1';
	flood_fill(game, map_temp, game -> x_player, game -> y_player);
	game -> map[y][x] = 'E';
	y = 0;
	while (game -> map[y])
	{
		x = 0;
		while (game -> map[y][x])
		{
			if (game -> map[y][x] == 'C' && map_temp[y][x] == '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	path_check(t_game *game, char *path)
{
	char	**map_temp;

	map_temp = read_map(path);
	if (!map_temp)
		return (0);
	fill_map(game, map_temp);
	flood_fill(game, map_temp, game -> x_player, game -> y_player);
	if (map_temp[game -> y_exit][game -> x_exit] == '1'
		&& check_coll_path(game, map_temp) == 1)
	{
		free_map(map_temp);
		return (1);
	}
	free_map(map_temp);
	return (0);
}
