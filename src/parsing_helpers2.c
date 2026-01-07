/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-06 20:37:26 by adadra            #+#    #+#             */
/*   Updated: 2026-01-06 20:37:26 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	parse_flags2(char *argv[], int *c, t_data *data)
{
	if ((ft_strncmp(argv[*c], "--simple", 9)) == 0)
		data->strategy = 0;
	else if ((ft_strncmp(argv[*c], "--medium", 9)) == 0)
		data->strategy = 1;
	else if ((ft_strncmp(argv[*c], "--complex", 10)) == 0)
		data->strategy = 2;
	else if ((ft_strncmp(argv[*c], "--adaptive", 11)) == 0)
		data->strategy = 3;
	else if ((ft_strncmp(argv[*c], "--bench", 8)) == 0)
		data->bench = 1;
	else
	{
		*c = 1;
		return (-1);
	}
	return (1);
}
