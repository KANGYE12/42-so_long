/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:22:43 by kanye             #+#    #+#             */
/*   Updated: 2025/08/02 15:08:29 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_ber_file(char *filename)
{
	size_t	file_length;

	file_length = ft_strlen(filename);
	if (file_length < 4 || ft_strcmp(filename + file_length - 4, ".ber") != 0)
		return (ERROR);
	return (SUCCESS);
}

void	check_ber_rectangular_and_assign_width(t_game *game, char *filename)
{
	int	expected_width;
	int	row;
	int	col;

	if (!game->map || !game->map[0])
		error_message("Map is empty or NULL", game);
	expected_width = ft_strlen(game->map[0]);
	row = 1;
	while (game->map[row] != NULL)
	{
		col = ft_strlen(game->map[row]);
		if (col != expected_width)
			error_message("Map is not rectangular", game);
		row++;
	}
	game->width = expected_width;
	if (!check_if_ber_file(filename))
		error_message("THE FILE IS NOT A .ber", game);
}

void	check_walls(t_game game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game.height)
	{
		if (row == 0 || row == game.height - 1)
		{
			col = 0;
			while (game.map[row][col])
			{
				if (game.map[row][col] != '1')
					error_message("ERROR: THE WALLS ARE NOT WELL CONFIGURED",
						&game);
				col++;
			}
		}
		if (game.map[row][0] != '1' || game.map[row][game.width - 1] != '1')
			error_message("ERROR: THE WALLS ARE NOT WELL CONFIGURED (sides)",
				&game);
		row++;
	}
}

static void	check_sprites_aux(t_game *game, int row, int column, int *sprites)
{
	if (game->map[row][column] != '0' && game->map[row][column] != 'P'
		&& game->map[row][column] != 'E' && game->map[row][column] != '1'
		&& game->map[row][column] != '0' && game->map[row][column] != 'C')
		error_message("INVALID CHARACTER SPRITE IN THE MAP", game);
	if (game->map[row][column] == 'P')
		sprites[0] = sprites[0] + 1;
	if (game->map[row][column] == 'E')
		sprites[1] = sprites[1] + 1;
	if (game->map[row][column] == 'C')
		sprites[2] = sprites[2] + 1;
}

void	check_sprites(t_game *game)
{
	int	row;
	int	column;
	int	sprites[3];

	row = 0;
	sprites[0] = 0;
	sprites[1] = 0;
	sprites[2] = 0;
	while (row < game->height)
	{
		column = 0;
		while (column < game->width)
		{
			check_sprites_aux(game, row, column, sprites);
			column++;
		}
		row++;
	}
	if (sprites[0] != 1 || sprites[1] != 1 || sprites[2] == 0)
		error_message("THERE IS AN ERROR IN THE CONFIGURATION OF THE SPRITES",
			game);
}
