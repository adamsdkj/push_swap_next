/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:28:49 by cbahry            #+#    #+#             */
/*   Updated: 2025/12/22 23:00:35 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(va_list args, const char spec)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (spec == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (spec == 'i' || spec == 'd')
		count = ft_itoa_printf(va_arg(args, int));
	else if (spec == 'u')
		count = ft_utoa(va_arg(args, unsigned int));
	else if (spec == 'p')
		count = ft_print_ptr(va_arg(args, void *));
	else if (spec == 'x')
		count = ft_print_hex(va_arg(args, unsigned int), 0, &count);
	else if (spec == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), 1, &count);
	return (count);
}

static int	is_valid_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;

	total = 0;
	va_start(args, format);
	if (!format)
		return (total);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			if (*format == '%')
				total += write(2, "%", 1);
			else if (is_valid_specifier(*format))
				total += ft_format(args, *format);
		}
		else if (*format != '%' && *format != '\0')
			total += write(2, format, 1);
		if (*format)
			format++;
	}
	va_end(args);
	return (total);
}
