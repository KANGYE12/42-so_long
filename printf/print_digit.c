/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:29:38 by kanye             #+#    #+#             */
/*   Updated: 2024/10/29 15:44:06 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_digit(int n)
{
	size_t	count;

	count = 0;
	if (n == INT_MIN)
		return (count += write(1, "-2147483648", 11));
	else if (n < 0)
	{
		count += write(1, "-", 1);
		n = n * -1;
		return (count + print_digit(n));
	}
	else if (n < 10)
		return (print_char(n + '0'));
	else
	{
		count = print_digit((n / 10));
		return (count + print_digit((n % 10)));
	}
}
