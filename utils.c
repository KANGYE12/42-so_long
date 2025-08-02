/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:26:54 by kanye             #+#    #+#             */
/*   Updated: 2025/08/02 13:42:20 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message, t_game *game)
{
	ft_putendl_fd(message, 1);
	clean_up_game(game);
	free_map(game->map, game->height);
	exit(1);
}

void	free_map(char **map, int height)
{
	int	row;

	row = 0;
	while (row < height)
	{
		free(map[row]);
		row++;
	}
	free(map);
}

int	valid_move(char tile, t_game *game)
{
	if (tile == '1')
	{
		ft_printf("You are hitting a tree :(\n");
		return (ERROR);
	}
	if ((tile == 'E' && game->coins_total != game->collected_coins))
	{
		ft_printf("You need to collect the remaining coins: %d\n",
			game->coins_total - game->collected_coins);
		return (ERROR);
	}
	return (SUCCESS);
}

int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
