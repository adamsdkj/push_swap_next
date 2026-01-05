/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:54:45 by cbahry            #+#    #+#             */
/*   Updated: 2025/12/22 23:30:25 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex_ptr(unsigned long n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_print_hex_ptr(n / 16, count);
	*count += write(1, &base[n % 16], 1);
	return (*count);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	int				count;

	address = (unsigned long) ptr;
	count = 0;
	if (address == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	ft_print_hex_ptr(address, &count);
	return (count);
}

int	ft_print_hex(unsigned int n, int is_upper, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (is_upper == 1)
		base = "0123456789ABCDEF";
	if (n >= 16)
		ft_print_hex(n / 16, is_upper, count);
	*count += write(1, &base[n % 16], 1);
	return (*count);
}
