/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:45:55 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/07 01:01:39 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void  sa(t_data **stack)
{
  t_stack *first;
  t_stack *second;

  if (!stack || !(*stack) || !(*stack)->a || !(*stack)->a->next)
    return ;
  first = (*stack)->a;
  second = first->next;
  first->next = second->next;
  second->next = first;
  (*stack)->a = second;
  write(1, "sa\n", 3);
}

void  ra(t_data **stack)
{
  t_stack *current;
  t_stack *second;
  
  if (!stack || !(*stack) || !(*stack)->a || !(*stack)->a->next)
    return ;
  current = (*stack)->a;
  second = (*stack)->a->next;
  while (current->next != NULL)
    current = current->next;
  current->next = (*stack)->a;
  (*stack)->a->next = NULL;
  (*stack)->a = second;
  write(1, "ra\n", 3);
}

void  rra(t_data **stack)
{
  t_stack *last;
  t_stack *before_last;

  if (!stack || !(*stack) || !(*stack)->a || !(*stack)->a->next)
    return ;
  before_last = (*stack)->a;
  while (before_last->next->next != NULL)
    before_last = before_last->next;
  last = before_last->next;
  before_last->next = NULL;
  last->next = (*stack)->a;
  (*stack)->a = last;
  write(1, "rra\n", 4);
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


int find_min_pos(t_stack *stack)
{
  t_stack *current;
  int pos;
  int min_pos;
  int min;

  if (!stack)
    return (-1);
  current = stack;
  pos = 0;
  min_pos = 0;
  min = stack->value;
  while (current)
  {
    if (current->value < min)
    {
      min = current->value;
      min_pos = pos;
    }
    current = current->next;
    pos++;
  }
  return (min_pos);
}

void  rotate_to_top(t_data **stack, int pos)
{
  int size;

  size = stack_size((*stack)->a);
  if (pos <= size/2)
  {
    while (pos > 0)
    {
      ra(stack);
      pos--;
    }
  }
  else
  {
    while (pos < size)
    {
      rra(stack);
      pos++;
    }
  }
}

void  selection_sort(t_data **stack)
{
  int min_pos;
  
  if (stack_is_sorted((*stack)->a))
    return ;
  if (stack_size((*stack)->a) == 2)
  {
    sa(stack);
    return ;
  }
  while ((*stack)->a != NULL)
  {
    min_pos = find_min_pos((*stack)->a);
    rotate_to_top(stack, min_pos);
    pb(stack);
  }
  while ((*stack)->b != NULL)
  {
    pa(stack);
  }
}

// int main(void)
// {
//   t_data *stack = malloc(sizeof(t_data));
//   stack->a = stack_new(1);
//   stack_push(&stack->a, stack_new(2));
//   stack_push(&stack->a, stack_new(3));
//   stack_push(&stack->a, stack_new(4));
//   stack_push(&stack->a, stack_new(5));
//   stack_push(&stack->a, stack_new(6));
//   stack_push(&stack->a, stack_new(7));
//   stack_push(&stack->a, stack_new(8));
//   // stack_print(stack->a);
//   selection_sort(&stack);
//   // stack_print(stack->a);
// }
