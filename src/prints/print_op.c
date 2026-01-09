/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-09 20:19:34 by adadra            #+#    #+#             */
/*   Updated: 2026-01-09 20:19:34 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    printops(t_stats    stats)
{
    int i;

    i = 0;
    printf("%d",stats.pb_count);
    while (i < stats.pb_count)
    {
        write(1, "pb\n", 3);
        i++;
    }
}