int this file we implemented the function necessary to initialize a stack with some additional function to free the allocated memory and to print the stack and the size of it  

### function prototype

```c
t_stack *stack_new(int value);
void stack_print(t_stack *head);
void stack_push(t_stack **head, t_stack *node);
void stack_free(t_stack **head);
int stack_size(t_stack *head);
```