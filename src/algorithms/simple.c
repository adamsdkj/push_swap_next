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

int find_min_pos(t_stack *stack) {
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
  while (current) {
    if (current->value < min) {
      min = current->value;
      min_pos = pos;
    }
    current = current->next;
    pos++;
  }
  return (min_pos);
}

void rotate_to_top(t_data *stack, int pos) {
  int size;

  size = stack_size(stack->a);
  if (pos <= size / 2) {
    while (pos > 0) {
      ra(stack, 1);
      pos--;
    }
  } else {
    while (pos < size) {
      rra(stack, 1);
      pos++;
    }
  }
}

void selection_sort(t_data *stack) {
  int min_pos;

  if (stack_is_sorted(stack->a))
    return;
  if (stack_size(stack->a) == 2) {
    sa(stack, 1);
    return;
  }
  while (stack->a != NULL) {
    min_pos = find_min_pos(stack->a);
    rotate_to_top(stack, min_pos);
    pb(stack);
  }
  while (stack->b != NULL) {
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
