/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:31:39 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/05 20:31:39 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void  rra(t_data *stack, int is_separate)
{
  t_stack *last;
  t_stack *before_last;

  if (!stack || !stack->a || stack->a->next)
    return ;
  before_last = stack->a;
  while (before_last->next->next != NULL)
    before_last = before_last->next;
  last = before_last->next;
  before_last->next = NULL;
  last->next = stack->a;
  stack->a = last;
  if (is_separate == 1)
  {
    stack->stats.rra_count += 1;
    stack->stats.total_ops += 1;
    write(1, "rra\n", 4);
  }
}

void  rrb(t_data *stack, int is_separate)
{
  t_stack *last;
  t_stack *before_last;

  if (!stack || !stack->b || !stack->b->next)
    return ;
  before_last = stack->b;
  while (before_last->next->next != NULL)
    before_last = before_last->next;
  last = before_last->next;
  before_last->next = NULL;
  last->next = stack->b;
  stack->b = last;
  if (is_separate == 1)
  {
    stack->stats.rrb_count += 1;
    stack->stats.total_ops += 1;
    write(1, "rrb\n", 4);
  }
}

void  rrr(t_data *stack)
{
  if (!stack || !stack->b || !stack->b->next
      || !stack->a || !stack->a->next)
    return ;
  rra(stack, 0);
  rrb(stack, 0);
  stack->stats.rrr_count += 1;
  stack->stats.total_ops += 1;
  write(1, "rrr\n", 4);
}

// int main(void)
// {
//   t_data  *stack = malloc(sizeof(t_data));
//   stack->a = stack_new(53);
//   stack_push(&stack->a, stack_new(35));
//   stack_push(&stack->a, stack_new(834));
//   stack_push(&stack->a, stack_new(85));
//   stack_print(stack->a);
//   rra(&stack);
//   ft_printf("\n");
//   stack_print(stack->a);
// }
