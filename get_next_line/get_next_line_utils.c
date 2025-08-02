/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:19:40 by kanye             #+#    #+#             */
/*   Updated: 2024/12/14 13:19:40 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_char;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	new_char = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (!new_char)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_char[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i] != '\0')
	{
		new_char[i + j] = s2[i];
		i++;
	}
	new_char[i + j] = '\0';
	return (new_char);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*sp;
	size_t	i;
	size_t	s_size;

	i = 0;
	s_size = ft_strlen(s);
	sp = (char *)malloc((s_size + 1) * sizeof(*s));
	if (!sp)
		return (NULL);
	while (i < s_size && s[i] != '\0')
	{
		sp[i] = s[i];
		i++;
	}
	sp[i] = '\0';
	return (sp);
}
