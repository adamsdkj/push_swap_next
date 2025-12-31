/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:06:31 by cbahry            #+#    #+#             */
/*   Updated: 2025/11/07 01:56:44 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_allocate(int n)
{
	char	*result;

	if (n < 0)
		result = malloc(ft_intlen(n) + 2);
	else
		result = malloc(ft_intlen(n) + 1);
	return (result);
}

static	char	*ft_fill_reverse(long num, size_t i, char *result)
{
	while (num)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	size_t	i;

	num = n;
	result = ft_allocate(n);
	if (!result)
		return (NULL);
	if (n < 0)
		result[ft_intlen(num) + 1] = '\0';
	else
		result[ft_intlen(num)] = '\0';
	if (num == 0)
	{
		result[0] = '0';
		return (result);
	}
	i = ft_intlen(num) - 1;
	if (num < 0)
	{
		num = num * -1;
		result[0] = '-';
		i = ft_intlen(num);
	}
	return (ft_fill_reverse(num, i, result));
}
