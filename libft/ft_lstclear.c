/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:37:52 by kanye             #+#    #+#             */
/*   Updated: 2025/03/15 19:10:49 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack		*temporal;
	t_stack		*next_node;

	temporal = *lst;
	while (temporal != NULL)
	{
		next_node = temporal->next;
		free(temporal);
		temporal = next_node;
	}
	*lst = NULL;
}
