/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 05:30:28 by cbahry            #+#    #+#             */
/*   Updated: 2025/11/07 16:15:39 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;

	i = 0;
	s_ptr = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char) c == *s_ptr)
			return (s_ptr);
		s_ptr = (unsigned char *) &s[i];
		s_ptr++;
		i++;
	}
	return (NULL);
}
