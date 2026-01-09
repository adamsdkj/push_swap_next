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

#include "push_swap.h"

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
	int		*sorted;
	t_stack	*current;
	int	left;
	int	right;
	int	mid;

	sorted = create_sorted_array(stack_a);
	current = stack_a;
	while (current)
	{
		left = 0;
		right = stack_size(stack_a) - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (sorted[mid] == current->value)
			{
				current->rank = mid;
				break ;
			}
			else if (sorted[mid] < current->value)
				left = mid + 1;
			else
				right = mid - 1;
		}
		current = current->next;
	}
	free(sorted);
}

int	find_pos_in_range(t_stack *a, int min, int max)
{
	int	pos = 0;
	while (a)
	{
		if (a->rank >= min && a->rank <= max)
			return pos;
		pos++;
		a = a->next;
	}
	return -1;
}

void	push_chunk(t_data *s, int min, int max)
{
	int	pos;
	int	size;
	int	mid;

	mid = (min + max) / 2;
	while (1)
	{
		pos = find_pos_in_range(s->a, min, max);
		if (pos == -1)
			break;
		size = stack_size(s->a);
		if (pos <= size / 2)
			while (pos--)
				ra(s, 1);
		else
			while (pos++ < size)
				rra(s, 1);
		pb(s);
		if (s->b->rank > mid)
			rb(s, 1);
	}
}

