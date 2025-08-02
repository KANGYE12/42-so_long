/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:18:50 by kanye             #+#    #+#             */
/*   Updated: 2024/12/14 13:18:50 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_each_line(char *buffer_accumulator)
{
	char	*line;
	size_t	i;

	if (!buffer_accumulator)
		return (NULL);
	i = 0;
	while (buffer_accumulator[i] != '\0' && buffer_accumulator[i] != '\n')
		i++;
	if (buffer_accumulator[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	if (buffer_accumulator[i] == '\n')
		ft_strlcpy(line, buffer_accumulator, i + 2);
	else
		ft_strlcpy(line, buffer_accumulator, i + 1);
	return (line);
}

static char	*process_buffer_accumulator(char *buffer_accumulator)
{
	size_t	i;
	char	*new_buffer;

	if (!buffer_accumulator)
		return (NULL);
	i = 0;
	while (buffer_accumulator[i] != '\0' && buffer_accumulator[i] != '\n')
		i++;
	if (buffer_accumulator[i] == '\n')
		i++;
	if (buffer_accumulator[i] == '\0')
	{
		free(buffer_accumulator);
		return (NULL);
	}
	new_buffer = ft_strdup(buffer_accumulator + i);
	free(buffer_accumulator);
	return (new_buffer);
}

static char	*update_buffer_accumulator(char *buffer_accumulator, char *buffer)
{
	char	*temporal;

	if (!buffer_accumulator)
		buffer_accumulator = ft_strdup("");
	temporal = buffer_accumulator;
	buffer_accumulator = ft_strjoin(buffer_accumulator, buffer);
	free(temporal);
	if (!buffer_accumulator)
		return (NULL);
	return (buffer_accumulator);
}

static int	read_file(int fd, char **buffer_accumulator)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		*buffer_accumulator = update_buffer_accumulator(*buffer_accumulator,
				buffer);
		if (!*buffer_accumulator)
		{
			free(buffer);
			return (-1);
		}
		if (ft_strchr(*buffer_accumulator, '\n') != NULL)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer_accumulator;
	char		*line;
	int			bytes_read;

	if (fd < 0)
		return (NULL);
	bytes_read = read_file(fd, &buffer_accumulator);
	if (bytes_read == -1)
	{
		free(buffer_accumulator);
		buffer_accumulator = NULL;
		return (NULL);
	}
	line = get_each_line(buffer_accumulator);
	buffer_accumulator = process_buffer_accumulator(buffer_accumulator);
	return (line);
}
