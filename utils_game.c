/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:33:10 by kanye             #+#    #+#             */
/*   Updated: 2025/08/02 13:42:00 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(t_game *game, int x, int y)
{
	char	next_tile;

	next_tile = game->map[y][x];
	if (next_tile == 'C')
		game->collected_coins++;
	else if (next_tile == 'E')
	{
		ft_printf("\nYOU WON THE GAME IN %d MOVES\n", game->moves + 1);
		free_map(game->map, game->height);
		clean_up_game(game);
		exit(0);
	}
	game->map[game->position_y][game->position_x] = '0';
	game->position_x = x;
	game->position_y = y;
	game->map[y][x] = 'P';
	game->moves++;
	ft_printf("MOVES: %d\n", game->moves);
}

void	get_player_position(t_game *game)
{
	int	col;
	int	row;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map[row][col] == 'P')
			{
				game->position_x = col;
				game->position_y = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	get_total_coins(t_game *game)
{
	int	col;
	int	row;
	int	total_coins;

	row = 0;
	total_coins = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map[row][col] == 'C')
				total_coins++;
			col++;
		}
		row++;
	}
	game->coins_total = total_coins;
}

void	clean_up_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
	{
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		if (game->coins)
			mlx_destroy_image(game->mlx, game->coins);
		if (game->exit)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
	}
	game->player = NULL;
	game->coins = NULL;
	game->exit = NULL;
	game->floor = NULL;
	game->wall = NULL;
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
}

int	close_window_hook(t_game *game)
{
	ft_printf("\nCLOSE THE WINDOWS PRESSING THE X BUTTON\n");
	clean_up_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
