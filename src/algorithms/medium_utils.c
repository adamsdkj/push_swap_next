/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <cbahry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:52:07 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/09 03:32:46 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	*sort_array(int *array, int stack_size)
{
	int	i;
	int	j;
	int	min_id;
	int	temp;

	i = 0;
	while (i < stack_size - 1)
	{
		min_id = i;
		j = i + 1;
		while (j < stack_size)
		{
			if (array[j] < array[min_id])
				min_id = j;
			j++;
		}
		if (min_id != i)
		{
			temp = array[i];
			array[i] = array[min_id];
			array[min_id] = temp;
		}
		i++;
	}
	return (array);
}

int	*create_sorted_array(t_stack *stack_a)
{
	int	i;
	int	size;
	int	*sorted_array;
	t_stack	*current;

	if (!stack_a)
		return (NULL);
	i = 0;
	size = stack_size(stack_a);
	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
		return (NULL);
	current = stack_a;
	while (current)
	{
		sorted_array[i] = current->value;
		current = current->next;
		i++;
	}
	sorted_array = sort_array(sorted_array, size);
	return (sorted_array);
}

void	assign_ranks(t_stack *stack_a)
{
	int		size;
	int		*sorted;
	t_stack	*current;
	int		i;

	i = 0;
	size = stack_size(stack_a);
	sorted = create_sorted_array(stack_a);
	current = stack_a;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted[i])
			{
				current->rank = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(sorted);
}

void	push_chunk(t_data *stack, int min_rank, int max_rank)
{
	int	mid;
	int	pushed;
	int	size;
	int	rotations;

	pushed = 0;
	mid = (min_rank + max_rank) / 2;
	size = stack_size(stack->a);
	rotations = 0;

	//ft_printf("BEFORE CHUNK [%d-%d]: A=%d, B=%d\n", min_rank, max_rank, stack_size(stack->a), stack_size(stack->b));

	while (pushed < (max_rank - min_rank + 1) && rotations < size)
	{
		if (stack->a->rank >= min_rank && stack->a->rank <= max_rank)
		{
			pb(stack);
			//ft_printf("After pb: A=%d, B=%d\n", stack_size(stack->a), stack_size(stack->b));
			if (stack->b && stack->b->rank > mid)
				rb(stack, 1);
			pushed++;
			rotations = 0;
		}
		else
		{
			ra(stack, 1);
			rotations++;
		}
	}

	//ft_printf("AFTER CHUNK [%d-%d]: A=%d, B=%d, pushed=%d\n", min_rank, max_rank, stack_size(stack->a), stack_size(stack->b), pushed);
}

void	push_all_chunks(t_data *stack, int chunk_size)
{
	int	total;
	int	chunk;
	int	min;
	int	max;

	total = stack_size(stack->a);
	chunk = 0;
	while (chunk * chunk_size < total)
	{
		min = chunk * chunk_size;
		max = min + chunk_size - 1;
		if (max >= total)
			max = total - 1;
		push_chunk(stack, min, max);
		chunk++;
	}
}
