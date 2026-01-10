/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_algorithms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <cbahry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:07:00 by adadra            #+#    #+#             */
/*   Updated: 2026/01/10 04:12:13 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algorithms(t_data *data, int is_print, char **str)
{
	if (data->strategy == 0)
		selection_sort(data, is_print);
	else if (data->strategy == 1)
		chunk_sort(data, is_print);
	else if (data->strategy == 2)
	{
		assign_ranks(data->a);
		radix_sort(data, is_print);
	}
	else if (data->strategy == 3)
		adaptive(data, str, is_print);
}

void	handle_algorithms(t_data *data)
{
	char	*str;

	str = NULL;
	if (data->bench == 0)
		select_algorithms(data, 1, &str);
	else if (data->bench == 1)
	{
		select_algorithms(data, 0, &str);
		bench(*data, str);
	}
}
