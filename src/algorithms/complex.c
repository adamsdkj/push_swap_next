/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 02:04:46 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/10 02:07:25 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = find_max_rank(a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_pass(t_data *stack, int bit, int is_print)
{
	int	i;
	int	size;

	size = stack_size(stack->a);
	i = 0;
	while (i < size)
	{
		if (((stack->a->rank >> bit) & 1) == 0)
			pb(stack, is_print);
		else
			ra(stack, 1, is_print);
		i++;
	}
	while (stack->b)
		pa(stack, is_print);
}

void	radix_sort(t_data *stack, int is_print)
{
	int	bit;
	int	max_bits;

	if (stack_size(stack->a) == 0)
		return ;
	max_bits = get_max_bits(stack->a);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(stack, bit, is_print);
		bit++;
	}
}

// int	main()
// {
// 	t_data data = data_init();
// 	stack_push(&data.a, stack_new(23));
// 	stack_push(&data.a, stack_new(62));
// 	stack_push(&data.a, stack_new(1));
// 	stack_push(&data.a, stack_new(4565));
// 	stack_push(&data.a, stack_new(0));
// 	stack_push(&data.a, stack_new(345));
// 	stack_push(&data.a, stack_new(765));
// 	stack_push(&data.a, stack_new(36));
// 	stack_push(&data.a, stack_new(5));
// 	stack_print(data.a);
// 	assign_ranks(data.a);
// 	radix_sort(&data, 1);
// 	ft_printf("%d", stack_is_sorted(data.a));
// }
