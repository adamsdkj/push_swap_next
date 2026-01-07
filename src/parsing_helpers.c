/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-05 01:31:58 by adadra            #+#    #+#             */
/*   Updated: 2026-01-05 01:31:58 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	int		is_neg;
	int		i;
	long	num;

	is_neg = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg = 1;
		i++;
	}
	num = 0;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		num = (num * 10) + nptr[i] - '0';
		i++;
	}
	if (is_neg)
		return (-num);
	return (num);
}

int	handle_number(long number, int *nb)
{
	if (!number)
		return (0);
	if (number > INT_MAX || number < INT_MIN)
		return (-1);
	*nb = (int) number;
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	is_dublicate(t_stack	**head)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!head)
		return ;
	first = *head;
	tmp = NULL;
	while (*head)
	{
		tmp = (*head)->next;
		while (tmp)
		{
			if ((*head)->value == tmp->value)
				print_error(&first);
			tmp = tmp->next;
		}
		*head = (*head)->next;
	}
	*head = first;
}
