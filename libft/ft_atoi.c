/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:34:19 by cbahry            #+#    #+#             */
/*   Updated: 2025/11/06 23:28:57 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	is_neg;
	int	i;
	int	num;

	is_neg = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg = 1;
		i++;
	}
	num = 0;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		num = (num * 10) + nptr[i] - '0';
		i++;
	}
	if (is_neg)
		return (-num);
	return (num);
}
