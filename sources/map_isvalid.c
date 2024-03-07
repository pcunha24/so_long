/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:47:41 by pedalexa          #+#    #+#             */
/*   Updated: 2024/03/06 13:43:51 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_wall_surrounded(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (x < game -> map_width)
	{
		if (game -> map[0][x] != '1'
			|| game -> map[game -> map_height - 1][x] != '1')
			return (0);
		x++;
	}
	while (y < game -> map_height - 1)
	{
		x = 0;
		while (x < game -> map_width)
		{
			if ((x == 0 || x == game -> map_width - 1)
				&& game -> map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_elements(t_game *game, int coll, int player, int exit)
{
	int	x;
	int	y;

	y = 0;
	while (game ->map[y])
	{
		x = 0;
		while (game ->map[y][x])
		{
			if (game ->map[y][x] == 'E')
				exit++;
			else if (game ->map[y][x] == 'P')
				player++;
			else if (game ->map[y][x] == 'C')
				coll++;
			else if (game -> map[y][x] != '0' && game -> map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	if (coll < 1 || exit != 1 || player != 1)
		return (0);
	else
		return (1);
}

static int	is_retangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game -> map_height)
	{
		if (ft_strlen(game -> map[i]) != game -> map_width)
			return (0);
		i++;
	}
	return (1);
}

int	map_isvalid(t_game *game)
{
	if (is_retangular(game) && check_elements(game, 0, 0, 0)
		&& is_wall_surrounded(game))
		return (1);
	else
		return (0);
}
