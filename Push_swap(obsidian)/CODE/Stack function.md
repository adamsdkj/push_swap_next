## Linear data structure

First we choose the stack to be linked list instead of array that's because when we do the operation `ra` (rotate stack a) in the case when we choose the stack as an array we have to shift all the element of the array by one element so that's a lot of operation in the case where we choose linked list we just have to place the first element in the end

at first the struct is going to look like this and we can add later extra filed 

```c
typedef strcut s_stack
{
	int value;
	struct s_stack *next;
}t_stack
```

setting both stack in a struct when passing to the function the prototype don't be this long and also easier to manage 

```c
typedef struct s_data
{
	t_stack *a;
	t_stack *b;
}t_data;
```
