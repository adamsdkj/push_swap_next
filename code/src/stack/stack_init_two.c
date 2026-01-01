/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-01 20:48:09 by adadra            #+#    #+#             */
/*   Updated: 2026-01-01 20:48:09 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_add_last(t_stack **head, t_stack *node)
{
	t_stack	*first;

	first = *head;
	if (!head || !node)
		return ;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	while ((*head)->next != NULL)
		*head = (*head)->next;
	(*head)->next = node;
	*head = first;
}

int	stack_is_sorted(t_stack *head)
{
	if (!head)
		return (1);
	while (head && head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
