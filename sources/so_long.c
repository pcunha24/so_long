/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:58:08 by pedalexa          #+#    #+#             */
/*   Updated: 2024/03/06 13:42:56 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_messages(char *message)
{
	ft_putstr_fd(message, 1);
	exit(1);
}

int	check_n_coll(t_game *game)
{
	int	x;
	int	y;
	int	n;

	y = 0;
	n = 0;
	while (game -> map[y])
	{
		x = 0;
		while (game -> map[y][x])
		{
			if (game -> map[y][x] == 'C')
				n++;
			x++;
		}
		y++;
	}
	return (n);
}

static void	map_width_height(t_game	*game)
{
	int	i;

	i = 0;
	game -> map_width = ft_strlen(game -> map[0]);
	game -> win_width = ft_strlen(game -> map[0]) * 32;
	while (game -> map[i])
	{
		i++;
	}
	game -> map_height = i;
	game -> win_height = i * 32;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_messages("Error! Invalid number of arguments!\n");
	if (!is_ber(argv[1]))
		error_messages("Error! Please insert a .ber map!\n");
	game.map = read_map(argv[1]);
	if (!game.map)
		error_messages("Error reading map!\n");
	map_width_height(&game);
	if (!map_isvalid(&game))
	{
		free_map(game.map);
		error_messages("Error! Please insert a valid map!\n");
	}
	if (!path_check(&game, argv[1]))
	{
		free_map(game.map);
		error_messages("Error! Collectables or exit are not reachable!");
	}
	game.n_coll = check_n_coll(&game);
	game_init(&game);
	gameplay(&game);
	mlx_loop(game.mlx);
	return (0);
}
