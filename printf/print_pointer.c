/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:29:50 by kanye             #+#    #+#             */
/*   Updated: 2024/10/29 15:15:29 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_pointer(void *ptr)
{
	size_t	counter;

	counter = 0;
	if (!ptr)
		counter += print_str("(nil)");
	else
	{
		counter += print_str("0x");
		counter += print_hex((unsigned long)ptr, 16, 'p');
	}
	return (counter);
}
