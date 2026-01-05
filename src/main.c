/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-01 14:06:04 by adadra            #+#    #+#             */
/*   Updated: 2026-01-01 14:06:04 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static t_stack	*parse_numbers2(char *argv[])
{
	t_stack	*head;
	char	**numbers;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	head = NULL;
	numbers = ft_split(argv[1], ' ');
	while (numbers[i])
	{
		if ((is_number(numbers[i]) == 0)
			|| (handle_number(ft_atol(numbers[i]), &nb) == -1))
		{
			print_error_split(&head, numbers);
			return (NULL);
		}
		stack_push(&head, stack_new(nb));
		nb = 0;
		i++;
	}
	ft_free(numbers);
	return (head);
}

t_stack	*parse_numbers(int argc, char *argv[])
{
	t_stack	*head;
	int		nb;
	int		i;

	i = 0;
	head = NULL;
	if (argc == 2)
		head = parse_numbers2(argv);
	else
	{
		while (++i < argc)
		{
			if ((is_number(argv[i]) == 0)
				|| handle_number(ft_atol(argv[i]), &nb) == -1)
			{
				print_error(&head);
				return (NULL);
			}
			stack_push(&head, stack_new(nb));
			nb = 0;
		}
	}
	if (!head)
		return (NULL);
	return (head);
}

t_stack	*parse_argument(int argc, char *argv[])
{
	if (argc < 2)
		return (NULL);
	else
	{
		if (((argv[1][0] == '-') && (argv[1][1] == '-')) && (argc > 2))
			printf("parse with args with numbers");
		else
			return (parse_numbers(argc, argv));
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*head;

	head = parse_argument(argc, argv);
	if (!head)
		return (0);
	stack_print(head);
	stack_free(&head);
	return (0);
}
