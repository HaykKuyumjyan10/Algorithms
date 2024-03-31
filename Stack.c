#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *collection;
    int capacity;
    int top; // Change 'size' to 'top' to represent the index of the top element
} Stack;

Stack *create_stack(int capacity) {
    if (capacity <= 0)
        return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL;

    stack->collection = malloc(sizeof(int) * capacity);
    if (stack->collection == NULL) {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->top = -1; // Initialize top to -1 to represent an empty stack
    return stack;
}

void destroy_stack(Stack *stack) {
    if (stack == NULL)
        return;

    free(stack->collection);
    free(stack);
}

bool is_full(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool is_empty(Stack *stack) {
    return stack->top == -1;
}

bool push(Stack *stack, int item) {
    if (stack == NULL || is_full(stack))
        return false;

    stack->collection[++stack->top] = item; // Increment top before assigning the value
    return true;
}

bool peek(Stack *stack, int *item) {
    if (stack == NULL || is_empty(stack))
        return false;

    *item = stack->collection[stack->top]; // Access the top element
    return true;
}

bool pop(Stack *stack, int *item) {
    if (stack == NULL || is_empty(stack))
        return false;

    *item = stack->collection[stack->top--]; // Decrement top after retrieving the value
    return true;
}

int main() {
    Stack *stack = create_stack(5);

    if (stack == NULL) {
        printf("Failed to create stack. Exiting...\n");
        return 1;
    }

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    int item;
    if (pop(stack, &item))
        printf("Popped item: %d\n", item);

    if (peek(stack, &item))
        printf("Top item: %d\n", item);

    destroy_stack(stack);
    return 0;
}
