#include <stdio.h>
#include <stdlib.h>

#define dataType int

struct Stack {
    dataType* stackPointer;
    int top;
};


#pragma region declareFuncs

void initStack(struct Stack* stack);
void traverseStack(struct Stack stack);
void push(struct Stack* stack, dataType value);
dataType pop(struct Stack* stack);

#pragma endregion declareFuncs


int main(int argc, char** argv) {
    struct Stack mainStack;
    dataType poppedValue;

    initStack(&mainStack);

    push(&mainStack, 4);
    push(&mainStack, 1);
    push(&mainStack, 3);
    push(&mainStack, 6);
    push(&mainStack, 7);

    traverseStack(mainStack);

    poppedValue = pop(&mainStack);
    poppedValue = pop(&mainStack);

    printf("%i\n", poppedValue);
    traverseStack(mainStack);

    return 0;
}


#pragma region funcs

void initStack(struct Stack* stack) {
    stack->stackPointer = malloc(sizeof(dataType));
    stack->top = 0;
}

void traverseStack(struct Stack stack) {
    for (int i = 0; i < stack.top; i++) {
        printf("Stack value at %i: %i\n", i, *(stack.stackPointer + i));
    }
}

void push(struct Stack* stack, dataType value) {
    stack->stackPointer = realloc(stack->stackPointer, stack->top + 2);
    *(stack->stackPointer + (stack->top++)) = value;
}

dataType pop(struct Stack* stack) {
    return *(stack->stackPointer + ((stack->top--) - 1));
}

#pragma endregion funcs