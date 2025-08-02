/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:38:44 by kanye             #+#    #+#             */
/*   Updated: 2025/08/02 14:00:06 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args_and_init(char **argv, t_game *game)
{
	read_map(argv[1], game);
	check_ber_rectangular_and_assign_width(game, argv[1]);
	check_walls(*game);
	check_sprites(game);
	get_player_position(game);
	get_total_coins(game);
	possible_path(game);
}

static void	*load_sprite(t_game *game, char *filename)
{
	void	*sprite;
	int		width;
	int		height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	sprite = mlx_xpm_file_to_image(game->mlx, filename, &width, &height);
	if (!sprite)
		error_message("THERE IS A PROBLEM IN CHANGING A XPM FILE TO IMAGE",
			game);
	return (sprite);
}

static void	load_all_sprites(t_game *game)
{
	game->player = load_sprite(game, "sprites/slime.xpm");
	game->coins = load_sprite(game, "sprites/coin.xpm");
	game->exit = load_sprite(game, "sprites/exit.xpm");
	game->floor = load_sprite(game, "sprites/floor.xpm");
	game->wall = load_sprite(game, "sprites/wall.xpm");
}

static void	load_map_auxiliar(t_game *game, int row, int column)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor, game->x_tile,
		game->y_tile);
	if (game->map[row][column] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			game->x_tile, game->y_tile);
	else if (game->map[row][column] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coins, game->x_tile,
			game->y_tile);
	else if (game->map[row][column] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, game->x_tile,
			game->y_tile);
	else if (game->map[row][column] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, game->x_tile,
			game->y_tile);
}

void	load_map(t_game *game)
{
	int	row;
	int	column;

	load_all_sprites(game);
	row = 0;
	while (row < game->height)
	{
		column = 0;
		while (column < game->width)
		{
			game->x_tile = column * TILE_SIZE;
			game->y_tile = row * TILE_SIZE;
			load_map_auxiliar(game, row, column);
			column++;
		}
		row++;
	}
}
