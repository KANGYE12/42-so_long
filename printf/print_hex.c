/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:29:38 by kanye             #+#    #+#             */
/*   Updated: 2024/10/29 15:24:11 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_hex(unsigned long int n, unsigned long base, char specifier)
{
	int			count;
	const char	*symbols;

	if (specifier == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_hex((n / base), base, specifier);
		return (count + print_hex((n % base), base, specifier));
	}
}
