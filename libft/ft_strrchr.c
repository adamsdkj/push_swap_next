/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 05:02:33 by cbahry            #+#    #+#             */
/*   Updated: 2025/11/06 23:03:57 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	*s_ptr;

	size = ft_strlen(s);
	s_ptr = (char *) &s[size];
	while (size >= 0)
	{
		if (s[size] == (char) c)
			return (s_ptr);
		s_ptr = (char *) &s[size];
		s_ptr--;
		if (size == 0)
			break ;
		size--;
	}
	return (NULL);
}
