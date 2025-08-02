/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:36:19 by kanye             #+#    #+#             */
/*   Updated: 2025/03/15 19:10:09 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char argument)
{
	return (argument != '\0' && (argument == 32 || (argument >= 9
				&& argument <= 13)));
}

long	ft_atoi(const char *argument)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (argument[i] != '\0' && is_space(argument[i]))
		i++;
	if (argument[i] == '-' || argument[i] == '+')
	{
		if (argument[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (argument[i] != '\0' && ft_isdigit(argument[i]))
	{
		result = result * 10 + (argument[i] - '0');
		i++;
	}
	return (result * sign);
}
