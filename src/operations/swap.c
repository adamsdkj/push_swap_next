/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:19:13 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/05 14:20:32 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"

void  sa(t_data *stack, int is_separate)
{
  t_stack *first;
  t_stack *second;

  if (!stack || !stack->a || !stack->a->next)
    return ;
  first = stack->a;
  second = first->next;
  first->next = second->next;
  second->next = first;
  stack->a = second;
  if (is_separate == 1)
  {
    stack.stats.sa_count += 1;
    stack.stats.total_ops += 1;
    write(1, "sa\n", 3);
  }
}

void  sb(t_data *stack, int is_separate)
{
  t_stack *first;
  t_stack *second;

  if (!stack || !stack->b || !stack->b->next)
    return ;
  first = stack->b;
  second = first->next;
  first->next = second->next;
  second->next = first;
  stack->b = second;
  if (is_separate == 1)
  {
    stack.stats.sb_count += 1;
    stack.stats.total_ops += 1;
    write(1, "sb\n", 3);
  }
}

void ss(t_data *stack)
{
  if (!stack || !stack->a || !stack->b)
    return ;
  sa(stack, 0);
  sb(stack, 0);
  stack.stats.ss_count += 1;
  stack.stats.total_ops += 1;
  write(1, "ss\n", 3);
}

// int main(void)
// {
//   t_data *stack;
//
//   stack = malloc(sizeof(t_data));
//   if (!stack)
//     return (1);
//   stack->a = stack_new(10);
//   stack_push(&stack->a, stack_new(20));
//   stack_push(&stack->a, stack_new(30));
//   ft_printf("stack a:\n");
//   stack_print(stack->a);
//   stack->b = stack_new(1);
//   stack_push(&stack->b, stack_new(2));
//   stack_push(&stack->b, stack_new(5));
//   ft_printf("stack b:\n");
//   stack_print(stack->b);
//   ft_printf("stack a sa:");
//   sa(&stack);
//   stack_print(stack->a);
//   ft_printf("stack b sb");
//   sb(&stack);
//   stack_print(stack->b);
//   ft_printf("both swapped at the same time");
//   ss(&stack);
//   stack_print(stack->a);
//   stack_print(stack->b);
//   stack_free(&stack->a);
//   stack_free(&stack->b);
//   free(stack);
//   return (0);
// }
