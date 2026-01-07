#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Your existing structures (adjust if different)
typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
}   t_stack;

typedef struct s_data
{
    t_stack *a;
    t_stack *b;
}   t_data;

// Your existing functions (declarations)
t_stack *stack_new(int value);
void stack_push(t_stack **stack, t_stack *new_node);
void selection_sort(t_data **stack);
int stack_size(t_stack *stack);

// Helper: Generate random array
void generate_random_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
    
    // Fisher-Yates shuffle
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Helper: Count operations by redirecting write calls
static int operation_count = 0;

// Override write to count operations instead of printing
ssize_t write(int fd, const void *buf, size_t count)
{
    (void)buf;
    if (fd == 1 && count > 0)  // stdout
        operation_count++;
    return count;
}

// Test function
void test_algorithm(int size, const char *name)
{
    int *arr = malloc(sizeof(int) * size);
    generate_random_array(arr, size);
    
    // Build stack
    t_data *stack = malloc(sizeof(t_data));
    stack->a = NULL;
    stack->b = NULL;
    
    // Push elements in reverse order (so first array element is on top)
    for (int i = size - 1; i >= 0; i--)
    {
        if (stack->a == NULL)
            stack->a = stack_new(arr[i]);
        else
            stack_push(&stack->a, stack_new(arr[i]));
    }
    
    // Reset counter and run algorithm
    operation_count = 0;
    selection_sort(&stack);
    
    // Print results
    printf("%-20s | Size: %-4d | Operations: %d\n", name, size, operation_count);
    
    // Cleanup
    free(arr);
    // TODO: Free stack nodes (add cleanup function)
}

// Test with specific patterns
void test_reverse_sorted(int size)
{
    t_data *stack = malloc(sizeof(t_data));
    stack->a = NULL;
    stack->b = NULL;
    
    // Build reverse sorted: size, size-1, ..., 2, 1
    for (int i = 1; i <= size; i++)
    {
        if (stack->a == NULL)
            stack->a = stack_new(i);
        else
            stack_push(&stack->a, stack_new(i));
    }
    
    operation_count = 0;
    selection_sort(&stack);
    
    printf("%-20s | Size: %-4d | Operations: %d\n", "Reverse Sorted", size, operation_count);
}

void test_already_sorted(int size)
{
    t_data *stack = malloc(sizeof(t_data));
    stack->a = NULL;
    stack->b = NULL;
    
    // Build sorted: 1, 2, ..., size
    for (int i = size; i >= 1; i--)
    {
        if (stack->a == NULL)
            stack->a = stack_new(i);
        else
            stack_push(&stack->a, stack_new(i));
    }
    
    operation_count = 0;
    selection_sort(&stack);
    
    printf("%-20s | Size: %-4d | Operations: %d\n", "Already Sorted", size, operation_count);
}

int main(void)
{
    srand(time(NULL));
    
    printf("\n=== PUSH_SWAP PERFORMANCE TEST ===\n\n");
    
    // Test small sizes
    printf("Small inputs:\n");
    test_already_sorted(3);
    test_reverse_sorted(3);
    test_algorithm(3, "Random (3)");
    printf("\n");
    
    test_already_sorted(5);
    test_reverse_sorted(5);
    test_algorithm(5, "Random (5)");
    printf("\n");
    
    test_already_sorted(8);
    test_reverse_sorted(8);
    test_algorithm(8, "Random (8)");
    printf("\n");
    
    // Test benchmark sizes
    printf("Benchmark tests:\n");
    test_algorithm(10, "Random (10)");
    test_algorithm(20, "Random (20)");
    test_algorithm(50, "Random (50)");
    test_algorithm(100, "Random (100)");
    test_algorithm(500, "Random (500)");
    printf("\n");
    
    // Multiple runs to get average
    printf("Average over 5 runs:\n");
    int total_ops = 0;
    for (int i = 0; i < 5; i++)
    {
        int *arr = malloc(sizeof(int) * 100);
        generate_random_array(arr, 100);
        
        t_data *stack = malloc(sizeof(t_data));
        stack->a = NULL;
        stack->b = NULL;
        
        for (int j = 99; j >= 0; j--)
        {
            if (stack->a == NULL)
                stack->a = stack_new(arr[j]);
            else
                stack_push(&stack->a, stack_new(arr[j]));
        }
        
        operation_count = 0;
        selection_sort(&stack);
        total_ops += operation_count;
        
        printf("  Run %d: %d operations\n", i + 1, operation_count);
        free(arr);
    }
    printf("  Average: %d operations\n", total_ops / 5);
    printf("\n");
    
    // Benchmark requirements
    printf("=== BENCHMARK REQUIREMENTS ===\n");
    printf("100 elements: < 2000 ops to pass, < 1500 for good, < 700 for excellent\n");
    printf("500 elements: < 12000 ops to pass, < 8000 for good, < 5500 for excellent\n");
    
    return 0;
}
