/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanye <kanye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:29:47 by kanye             #+#    #+#             */
/*   Updated: 2024/10/29 15:40:17 by kanye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((va_arg(ap, int)));
	else if (specifier == 'x')
		count += print_hex((long)(va_arg(ap, unsigned int)), 16, 'x');
	else if (specifier == 'X')
		count += print_hex((long)(va_arg(ap, unsigned int)), 16, 'X');
	else if (specifier == 'u')
		count += print_hex((long)va_arg(ap, unsigned int), 10, 'u');
	else if (specifier == 'p')
		count += print_pointer((va_arg(ap, void *)));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
