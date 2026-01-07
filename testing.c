/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-07 19:38:26 by adadra            #+#    #+#             */
/*   Updated: 2026-01-07 19:38:26 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pppp(t_data *data)
{    
    if (!data)
        return ;
    stack_push(&(data->b), stack_new(data->a->value));   
}

int main(void)
{
    t_data data;
    data = data_init();
    stack_push(&(data.a), stack_new(10));
    stack_push(&(data.a), stack_new(20));
    stack_push(&(data.a), stack_new(30));
    
    pppp(&data);
    stack_print(data.a);
    printf("\n-------------\n");
    stack_print(data.b);
    return (0);
}