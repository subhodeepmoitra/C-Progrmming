#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int isEmpty(Node** stack) {
    return *stack == NULL;
}

void push(Node** stack, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = *stack; 
    *stack = newNode;       
}

int pop(Node** stack)
{
    if (isEmpty(stack)) {
        printf("Stack Underflow...\n");
        return -1;
    }

    Node* temp = *stack;
    int poppedValue = temp->data;

    *stack = (*stack)->next; 
    free(temp);

    return poppedValue;
}

int peek(Node** stack)
{
    if (!isEmpty(stack))
        return (*stack)->data;
    else
        return -1;
}

void printStack(Node** stack)
{
    Node* temp = *stack;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node* stack = NULL; //Node* stack holds the addr of the initial node
    int choice, value;

    while (1) {
        printf("\n********** Stack Menu **********\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &value);
            push(&stack, value);
            printf("%d pushed to stack.\n", value);
            break;

        case 2:
            value = pop(&stack);
            if (value != -1)
                printf("Popped value: %d\n", value);
            break;

        case 3:
            value = peek(&stack);
            if (value != -1)
                printf("Top element: %d\n", value);
            else
                printf("Stack is empty.\n");
            break;

        case 4:
            printf("Current Stack: ");
            printStack(&stack);
            break;

        case 5:
            printf("Exiting...\n");
            while (!isEmpty(&stack))
                pop(&stack);
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
