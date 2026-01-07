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

float	compute_disorder(t_stack *a)
{
	t_stack		*comp;
	float		mistake;
	float		total_pairs;
	float		disorder;

	disorder = 0.0;
	mistake = 0.0;
	total_pairs = 0.0;
	comp = NULL;
	if (!a)
		return (0);
	while (a)
	{
		comp = a->next;
		while (comp)
		{
			total_pairs += 1;
			if (a->value > comp->value)
				mistake += 1;
			comp = comp->next;
		}
		a = a->next;
	}
	disorder = mistake / total_pairs;
	return (disorder);
}

void  stack_free_all(t_data **stack)
{
  if (!stack || !(*stack))
    return ;
  stack_free(&(*stack)->a);
  stack_free(&(*stack)->b);
  free(*stack);
  *stack = NULL;
}
