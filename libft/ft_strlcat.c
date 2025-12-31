/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 02:50:23 by cbahry            #+#    #+#             */
/*   Updated: 2025/11/07 17:05:07 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	src_len = ft_strlen(src);
	while ((k < size) && (dst[k] != '\0'))
		k++;
	if (size <= k)
		return (size + src_len);
	i = k;
	j = 0;
	if (size > 0)
	{
		while ((src[j] != '\0') && (i < size - 1))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (src_len + k);
}
