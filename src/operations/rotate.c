/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:18:02 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/05 19:18:02 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void  ra(t_data *stack, int is_separate)
{
  t_stack *current;
  t_stack *second;
  
  if (!stack || !stack->a || !stack->a->next)
    return ;
  current = stack->a;
  second = stack->a->next;
  while (current->next != NULL)
    current = current->next;
  current->next = stack->a;
  stack->a->next = NULL;
  stack->a = second;
  if (is_separate == 1)
  {
    stack.stats.ra_count += 1;
    stack.stats.total_ops += 1;
    write(1, "ra\n", 3);
  }
}

void  rb(t_data *stack, int is_separate)
{
  t_stack *current;
  t_stack *second;
  
  if (!stack || !stack->b || !stack->b->next)
    return ;
  current = stack->b;
  second = stack->b->next;
  while (current->next != NULL)
    current = current->next;
  current->next = stack->b;
  stack->b->next = NULL;
  stack->b = second;
  if (is_separate == 1)
  {
    stack.stats.rb_count += 1;
    stack.stats.total_ops += 1;
    write(1, "rb\n", 3);
  }
}

void  rr(t_data *stack)
{
  if (!stack || !stack->a || !stack->a->next
      || !stack->b || !stack->b->next)
    return ;
  ra(stack, 0);
  rb(stack, 0);
  stack.stats.rr_count += 1;
  stack.stats.total_ops += 1;
  write(1, "rr\n", 3);
}

// int main(void)
// {
//   t_data *stack = malloc(sizeof(t_data));
//   if (!stack)
//     return (1);
//   stack->a = stack_new(10);
//   stack_push(&stack->a, stack_new(32));
//   stack_push(&stack->a, stack_new(62));
//   stack_print(stack->a);
//   ra(&stack);
//   stack_print(stack->a);
// }
