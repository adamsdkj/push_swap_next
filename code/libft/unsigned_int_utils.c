/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:39:12 by cbahry            #+#    #+#             */
/*   Updated: 2025/12/22 23:31:06 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen_u(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_allocate_u(unsigned int n)
{
	char	*result;

	if (n < 0)
		result = malloc(ft_intlen_u(n) + 2);
	else
		result = malloc(ft_intlen_u(n) + 1);
	return (result);
}

void	ft_fill_reverse_u(unsigned int num, int i, char *result)
{
	int	k;

	while (num)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	k = 0;
	while (result[k])
	{
		write(1, &result[k], 1);
		k++;
	}
	free(result);
}

int	ft_utoa(unsigned int n)
{
	char	*result;
	int		i;

	result = ft_allocate_u(n);
	if (!result)
		return (0);
	result[ft_intlen_u(n)] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		write(1, &result[0], 1);
		free(result);
		return (1);
	}
	i = ft_intlen_u(n) - 1;
	if (n < 0)
	{
		n = n * -1;
		result[0] = '-';
	}
	ft_fill_reverse_u(n, i, result);
	return (ft_intlen_u(n));
}
