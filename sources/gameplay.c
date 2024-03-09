/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:47:35 by pedalexa          #+#    #+#             */
/*   Updated: 2024/03/09 15:13:13 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	ft_putstr_fd("Number of moves: ", 1);
	ft_putnbr_fd(game -> n_moves++, 1),
	ft_putchar_fd('\n', 1);
}

static void	player_movement(int keycode, t_game *game)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game -> x_player -= 1;
		move_left(game);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game -> y_player -= 1;
		move_up(game);
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game -> y_player += 1;
		move_down(game);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game -> x_player += 1;
		move_right(game);
	}
}

static int	keypressed(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_game(game);
	else
		player_movement(keycode, game);
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game -> win, 2, 1L << 0, keypressed, game);
	mlx_hook(game->win, 17, 1L << 17, destroy_game, game);
	mlx_hook(game->win, 9, 1L << 21, draw_map, game);
}
