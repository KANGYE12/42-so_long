/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_exit_accesibility.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:21:40 by kanye             #+#    #+#             */
/*   Updated: 2025/08/03 17:00:05 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || y >= game->height || x >= game->width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		game->reachable_coins++;
	if (map[y][x] == 'E')
	{
		game->reachable_exit = 1;
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x, y - 1, game);
	flood_fill(map, x, y + 1, game);
}

void	possible_path(t_game *game)
{
	char	**copy_of_map;

	copy_of_map = copy_map(game->map, game->height);
	if (!copy_of_map)
		error_message("THE MAP WAS NOT WELL COPIED", game);
	flood_fill(copy_of_map, game->position_x, game->position_y, game);
	if (game->reachable_coins != game->coins_total)
		error_message("IS NOT POSSIBLE TO ACCESS ALL THE COINS", game);
	if (game->reachable_exit != 1)
		error_message("IS NOT POSSIBLE TO ACCESS THE EXIT", game);
	free_map(copy_of_map, game->height);
}
