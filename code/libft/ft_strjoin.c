/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:24:55 by cbahry            #+#    #+#             */
/*   Updated: 2025/11/03 15:58:05 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(total_size + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, total_size + 1);
	ft_strlcat(result, s2, total_size + 1);
	return (result);
}
