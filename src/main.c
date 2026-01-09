/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <cbahry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:06:04 by adadra            #+#    #+#             */
/*   Updated: 2026/01/09 19:53:48 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*parse_numbers2(char *argv[], int start)
{
	t_stack	*head;
	char	**numbers;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	head = NULL;
	numbers = ft_split(argv[1 + start], ' ');
	while (numbers[i])
	{
		if ((is_number(numbers[i]) == 0)
			|| (handle_number(ft_atol(numbers[i]), &nb) == -1))
			print_error_split(&head, numbers);
		stack_add_last(&head, stack_new(nb));
		nb = 0;
		i++;
	}
	ft_free(numbers);
	return (head);
}

t_stack	*parse_numbers(int argc, char *argv[], int start)
{
	t_stack	*head;
	int		nb;
	int		i;

	i = start;
	head = NULL;
	nb = 0;
	if (argc == 2 + start)
		head = parse_numbers2(argv, start);
	else
	{
		while (++i < argc)
		{
			if ((is_number(argv[i]) == 0)
				|| handle_number(ft_atol(argv[i]), &nb) == -1)
				print_error(&head);
			stack_add_last(&head, stack_new(nb));
			nb = 0;
		}
	}
	if (!head)
		return (NULL);
	return (head);
}

t_stack	*parse_flags(int argc, char *argv[], t_data *data)
{
	int		count;
	t_stack	*result;

	count = 1;
	while (count <= 2)
	{
		if (parse_flags2(argv, &count, data) == -1)
			break ;
		if (count == 2)
			break ;
		count++;
	}
	result = parse_numbers(argc, argv, count);
	return (result);
}

t_data	parse_argument(int argc, char *argv[])
{
	t_data	data;
	t_stack	*result;

	data = data_init();
	result = NULL;
	if (argc < 2)
		return (data_init());
	else
	{
		if ((ft_strncmp(argv[1], "-", 1) == 0) && (argc > 2))
		{
			result = parse_flags(argc, argv, &data);
			is_dublicate(&result);
		}
		else
		{
			result = parse_numbers(argc, argv, 0);
			is_dublicate(&result);
		}
	}
	data.a = result;
	return (data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data = data_init();
	data = parse_argument(argc, argv);
	chunk_sort(&data);
	// stack_print(data.a);
	return (0);
}
