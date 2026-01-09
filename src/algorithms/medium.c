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

void	chunk_sort(t_data *stack)
{
	int	size;
	int	chunk_size;

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
	push_all_chunks(stack, chunk_size);
	push_back_to_a(stack);
}

// int	main(void)
// {
// 	t_data	data = data_init();

// 	stack_push(&data.a , stack_new(1));
// 	stack_push(&data.a, stack_new(63));
// 	stack_push(&data.a, stack_new(0));
// 	stack_push(&data.a, stack_new(30));
// 	stack_push(&data.a, stack_new(94));
// 	stack_push(&data.a, stack_new(8));
// 	stack_push(&data.a, stack_new(75));
// 	stack_push(&data.a, stack_new(52));
// 	stack_push(&data.a, stack_new(31));
// 	stack_push(&data.a, stack_new(74));
// 	stack_push(&data.a, stack_new(55));
// 	stack_push(&data.a, stack_new(22));
// 	stack_push(&data.a, stack_new(37));
// 	stack_push(&data.a, stack_new(70));
// 	stack_push(&data.a, stack_new(23));
// 	stack_push(&data.a, stack_new(38));
// 	stack_push(&data.a, stack_new(72));
// 	stack_push(&data.a, stack_new(65));
// 	stack_push(&data.a, stack_new(126));
// 	stack_push(&data.a, stack_new(7777));
// 	stack_push(&data.a, stack_new(66));
// 	stack_push(&data.a, stack_new(233));
// 	stack_push(&data.a, stack_new(694));
// 	stack_push(&data.a, stack_new(7));
// 	stack_push(&data.a, stack_new(40));
// 	stack_push(&data.a, stack_new(84));
// 	stack_push(&data.a, stack_new(4));
// 	stack_push(&data.a, stack_new(20));
// 	stack_push(&data.a, stack_new(13));
// 	stack_push(&data.a, stack_new(3));
// 	stack_push(&data.a, stack_new(953));
// 	stack_push(&data.a, stack_new(3455));
// 	stack_push(&data.a, stack_new(235));
// 	stack_push(&data.a, stack_new(3467));
// 	stack_push(&data.a, stack_new(5));
// 	stack_push(&data.a, stack_new(32345));
// 	stack_push(&data.a, stack_new(35));
// 	//ft_printf("\n----------------------------\n");
// 	//stack_print(data.a);
// 	//ft_printf("\n----------------------------\n");
// 	chunk_sort(&data);
// 	//ft_printf("%d\n", stack_is_sorted(data.a));
// 	//stack_print(data.a);
// 	//ft_printf("%d", stack_size(data.a));
// }
