/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:37:03 by kanye             #+#    #+#             */
/*   Updated: 2025/08/07 13:28:47 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *filename, t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_message("ERROR IN OPEN THE FILE", game);
	game->height = count_lines(filename);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
	{
		close(fd);
		error_message("MEMORY ALLOCATION FAILED", game);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map[i++] = line;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}
