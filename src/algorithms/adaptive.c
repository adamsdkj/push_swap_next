/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-10 00:44:04 by adadra            #+#    #+#             */
/*   Updated: 2026-01-10 00:44:04 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	adaptive(t_data *data, char **str, int is_print)
{
	if (data->stats.disorder < 0.2)
	{
		selection_sort(data, is_print);
		*str = "/ O(n²)";
	}
	else if (data->stats.disorder >= 0.2 && data->stats.disorder < 0.5)
	{
		chunk_sort(data, is_print);
		*str = "/ O(n√n)";
	}
	else if (data->stats.disorder >= 0.5)
	{
		printf("complex sorting");
		*str = "/ O(nlogn)";
	}
}
