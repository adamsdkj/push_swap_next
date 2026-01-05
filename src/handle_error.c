/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-05 01:40:56 by adadra            #+#    #+#             */
/*   Updated: 2026-01-05 01:40:56 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	print_error(t_stack **head)
{
	stack_free(head);
	write(2, "Error\n", 6);
}

void	print_error_split(t_stack **head, char **numbers)
{
	ft_free(numbers);
	stack_free(head);
	write(2, "Error\n", 6);
}
