/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:37:03 by kanye             #+#    #+#             */
/*   Updated: 2025/08/05 14:08:12 by kanye            ###   ########.fr       */
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
	game->height = count_lines(filename);
	if (fd < 0)
		error_message("ERROR IN OPEN THE FILE", game);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		error_message("MEMORY ALLOCATION FAILED", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}
