/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-09 22:14:14 by adadra            #+#    #+#             */
/*   Updated: 2026-01-09 22:14:14 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strategy_name(int i)
{
	char	*strategy;

	strategy = NULL;
	if (i == 0)
		return (strategy = "Simple / O(n²)");
	else if (i == 1)
		return (strategy = "Medium / O(n√n)");
	else if (i == 2)
		return (strategy = "Simple / O(nlogn)");
	else if (i == 3)
		return (strategy = "Adaptive we get this from adaptive fun");
	return (strategy);
}

void	print_float(float n, int precision)
{
	int		int_part;
	float	frac;
	int		frac_part;
	int		pow;
	int		i;

	int_part = (int)n;
	frac = n - int_part;
	pow = 1;
	i = 0;
	while (i < precision)
	{
		pow *= 10;
		i++;
	}
	frac_part = (int)(frac * pow + 0.5f);
	ft_printf("%d.%d", int_part, frac_part);
}

void	bench(t_data data)
{	
	ft_printf("[bench]  disorder:   ");
	print_float(data.stats.disorder * 100, 2);
	ft_printf("%%\n");
	ft_printf("[bench]  strategy:   %s\n", strategy_name(data.strategy));
	ft_printf("[bench]  total_ops:  %d\n", data.stats.total_ops);
	ft_printf("[bench]  sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
		data.stats.sa_count, data.stats.sb_count,
		data.stats.ss_count, data.stats.pa_count, data.stats.pb_count);
	ft_printf("[bench]  ra:  %d  rb:  %d  rr:  %d	",
		data.stats.ra_count, data.stats.rb_count,
		data.stats.rr_count);
	ft_printf("rra:  %d  rrb:  %d  rrr:  %d\n",
		data.stats.rra_count,
		data.stats.rrb_count, data.stats.rrr_count);
}
