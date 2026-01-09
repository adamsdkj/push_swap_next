/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-01 14:07:16 by adadra            #+#    #+#             */
/*   Updated: 2026-01-01 14:07:16 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = value;
	node->next = NULL;
	return (node);
}

void	stack_print(t_stack *head)
{
	int	i;

	i = 0;
	if (!head)
		return ;
	while (head)
	{
		ft_printf("%d: %d\n", i++, head->value);
		head = head->next;
	}
}

void	stack_push(t_stack **head, t_stack *node)
{
	if (!head || !node)
		return ;
	node->next = *head;
	*head = node;
}

void	stack_free(t_stack **head)
{
	t_stack	*current;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
	*head = NULL;
}

int	stack_size(t_stack *head)
{
	int	i;

	i = 0;
	if (!head)
		return (0);
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}
