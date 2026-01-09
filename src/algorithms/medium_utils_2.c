/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 01:40:14 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/09 01:40:14 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_stack *b)
{
	int	max_rank;
	int	pos;
	int i;
	t_stack	*current;

	if (!b)
		return (0);
	max_rank = b->rank;
	pos = 0;
	i = 0;
	current = b;
	while (current)
	{
		if (current->rank > max_rank)
		{
			max_rank = current->rank;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

int	find_max_rank(t_stack *b)
{
	int		max_rank;
	t_stack	*current;

	if (!b)
		return (-1);
	max_rank = b->rank;
	current = b->next;
	while (current)
	{
		if (current->rank > max_rank)
			max_rank = current->rank;
		current = current->next;
	}
	return (max_rank);
}

void	push_all_chunks(t_data *stack, int chunk_size)
{
	int	total;
	int	i;
	int	min;
	int	max;

	if (chunk_size <= 0)
		chunk_size = 1 ;
	total = stack_size(stack->a);
	i = 0;
	while (i * chunk_size < total)
	{
		min = i * chunk_size;
		max = min + chunk_size - 1;
		if (max >= total)
			max = total - 1;
		push_chunk(stack, min, max);
		i++;
	}
}

void	push_back_to_a(t_data *stack)
{
	int	pos;
	int	size;

	while (stack->b)
	{
		if (stack->b->rank == find_max_rank(stack->b))
		{
			pa(stack);
			continue ;
		}
		size = stack_size(stack->b);
		pos = find_max_pos(stack->b);
		if (pos <= size / 2)
		{
			while (pos > 0)
			{
				rb(stack, 1);
				pos--;
			}
		}
		else
		{
			while (pos < size)
			{
				rrb(stack, 1);
				pos++;
			}
		}
		pa(stack);
	}
}

