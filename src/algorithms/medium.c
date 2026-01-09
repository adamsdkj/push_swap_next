/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <cbahry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:59:13 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/09 03:37:13 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_data *stack, int is_print)
{
	int	size;
	int	chunk_size;

	if (stack_is_sorted(stack->a) == 1)
		return ;
	size = stack_size(stack->a);
	if (size <= 1)
		return ;
	assign_ranks(stack->a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	if (chunk_size < 1)
		chunk_size = 1;
	push_all_chunks(stack, chunk_size, is_print);
	push_back_to_a(stack, is_print);
}
