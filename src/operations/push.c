/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:59:44 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/05 16:59:44 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void  pa(t_data **stack)
{
  t_stack *first_a;
  t_stack *first_b;
 
  if (!stack || !(*stack) || !(*stack)->b)
    return ;
  first_a = (*stack)->a;
  first_b = (*stack)->b;
  (*stack)->b = (*stack)->b->next;
  first_b->next = first_a;
  (*stack)->a = first_b;
  write(1, "pa\n", 3);
}

void  pb(t_data **stack)
{

  t_stack *first_a;
  t_stack *first_b;
 
  if (!stack || !(*stack) || !(*stack)->a)
    return ;
  first_a = (*stack)->a;
  first_b = (*stack)->b;
  (*stack)->a = (*stack)->a->next;
  first_a->next = first_b;
  (*stack)->b = first_a;
  write(1, "pb\n", 3);
}

// int main(void)
// {
//   t_data *stack = malloc(sizeof(t_data));
//   if (!stack)
//     return (1);
//   stack->a = stack_new(1);
//   stack_push(&stack->a, stack_new(2));
//   stack_push(&stack->a, stack_new(4));
//   // stack->b = stack_new(10);
//   // stack_push(&stack->b, stack_new(32));
//   // stack_push(&stack->b, stack_new(98));
//   stack_print(stack->a);
//   // stack_print(stack->b);
//   pa(&stack);
//   stack_print(stack->a);
//   stack_print(stack->b);
//   stack_free(&stack->a);
//   stack_free(&stack->b);
//   free(stack);
//   return (0);
// }

// int main(void)
// {
//   t_data *data;
//   data = malloc(sizeof(t_data));
//   if (!data)
//     return (1);
//   *data = data_init();
//   stack_push(&(data->a), stack_new(10));
//   stack_push(&(data->a), stack_new(20));
//   stack_push(&(data->a), stack_new(30));


//   pb(&data);
//   stack_print(data->a);
//   printf("\n-------\n");
//   stack_print(data->b);
  
//   stack_free_all(&data);
//   return (0);
// }