/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:48:00 by pedalexa          #+#    #+#             */
/*   Updated: 2024/03/09 15:12:48 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game -> map[game -> y_player][game -> x_player] == 'E'
	&& game -> n_coll == 0)
	{
		mlx_clear_window(game -> mlx, game -> win);
		print_moves(game);
		game -> endgame = 1;
		draw_map(game);
	}
	else if (game -> map[game -> y_player][game -> x_player] == '1'
	|| (game -> map[game -> y_player][game -> x_player] == 'E'
	&& game -> n_coll != 0))
		game -> y_player += 1;
	else
	{
		mlx_clear_window(game -> mlx, game -> win);
		print_moves(game);
		if (game -> map[game -> y_player][game -> x_player] == 'C')
			game -> n_coll--;
		game -> map[game -> y_player][game -> x_player] = 'P';
		game -> map[game -> y_player + 1][game -> x_player] = '0';
		draw_map(game);
	}
}

void	move_down(t_game *game)
{
	if (game -> map[game -> y_player][game -> x_player] == 'E'
	&& game -> n_coll == 0)
	{
		mlx_clear_window(game -> mlx, game -> win);
		print_moves(game);
		game -> endgame = 1;
		draw_map(game);
	}
	else if (game -> map[game -> y_player][game -> x_player] == '1'
	|| (game -> map[game -> y_player][game -> x_player] == 'E'
	&& game -> n_coll != 0))
		game -> y_player -= 1;
	else
	{
		mlx_clear_window(game -> mlx, game -> win);
		print_moves(game);
		if (game -> map[game -> y_player][game -> x_player] == 'C')
			game -> n_coll--;
		game -> map[game -> y_player][game -> x_player] = 'P';
		game -> map[game -> y_player - 1][game -> x_player] = '0';
		draw_map(game);
	}
}

void	move_left(t_game *game)
{
	if (game -> map[game -> y_player][game -> x_player] == 'E'
	&& game -> n_coll == 0)
	{
		mlx_clear_window(game -> mlx, game -> win);
		print_moves(game);
		game -> endgame = 1;
		draw_map(game);
	}
	else if (game -> map[game -> y_player][game -> x_player] == '1'
	|| (game -> map[game -> y_player][game -> x_player] == 'E'
	&& game -> n_coll != 0))
		game -> x_player += 1;
	else
	{
		mlx_clear_window(game -> mlx, game -> win);
		print_moves(game);
		if (game -> map[game -> y_player][game -> x_player] == 'C')
			game -> n_coll--;
		game -> map[game -> y_player][game -> x_player] = 'P';
		game -> map[game -> y_player][game -> x_player + 1] = '0';
		draw_map(game);
	}
}

void	move_right(t_game *game)
{
	if (game -> map[game -> y_player][game -> x_player] == 'E'
	&& game -> n_coll == 0)
	{
		mlx_clear_window(game -> mlx, game -> win);
		print_moves(game);
		game -> endgame = 1;
		draw_map(game);
	}
	else if (game -> map[game -> y_player][game -> x_player] == '1' ||
	(game -> map[game -> y_player][game -> x_player] == 'E'
	&& game -> n_coll != 0))
		game -> x_player -= 1;
	else
	{
		mlx_clear_window(game -> mlx, game -> win);
		print_moves(game);
		if (game -> map[game -> y_player][game -> x_player] == 'C')
			game -> n_coll--;
		game -> map[game -> y_player][game -> x_player] = 'P';
		game -> map[game -> y_player][game -> x_player - 1] = '0';
		draw_map(game);
	}
}
