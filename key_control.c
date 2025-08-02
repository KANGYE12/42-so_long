/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:52:28 by kanye             #+#    #+#             */
/*   Updated: 2025/08/02 13:47:37 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_key(t_game *game)
{
	int	y;
	int	x;

	y = game->position_y - 1;
	x = game->position_x;
	if (!valid_move(game->map[y][x], game))
		return ;
	update_player(game, x, y);
}

void	s_key(t_game *game)
{
	int	y;
	int	x;

	y = game->position_y + 1;
	x = game->position_x;
	if (!valid_move(game->map[y][x], game))
		return ;
	update_player(game, x, y);
}

void	a_key(t_game *game)
{
	int	y;
	int	x;

	y = game->position_y;
	x = game->position_x - 1;
	if (!valid_move(game->map[y][x], game))
		return ;
	update_player(game, x, y);
}

void	d_key(t_game *game)
{
	int	y;
	int	x;

	y = game->position_y;
	x = game->position_x + 1;
	if (!valid_move(game->map[y][x], game))
		return ;
	update_player(game, x, y);
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		w_key(game);
	else if (keycode == KEY_A)
		a_key(game);
	else if (keycode == KEY_D)
		d_key(game);
	else if (keycode == KEY_S)
		s_key(game);
	else if (keycode == KEY_ESC)
	{
		ft_printf("\nEXITING FROM THE GAME AFTER PRESSING ESC\n");
		free_map(game->map, game->height);
		clean_up_game(game);
		exit(0);
	}
	load_map(game);
	return (0);
}
