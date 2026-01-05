/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:53:48 by cbahry            #+#    #+#             */
/*   Updated: 2025/12/22 23:30:53 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	if (s == 0)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (s && *s)
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}
