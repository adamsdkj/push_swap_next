/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 04:32:40 by cbahry            #+#    #+#             */
/*   Updated: 2025/11/06 23:02:03 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s_ptr;

	s_ptr = (char *) s;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char) c)
			return ((char *) s_ptr);
		i++;
		s_ptr++;
	}
	return (NULL);
}
