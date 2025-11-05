#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// fuction to insert data before the head node
int insertBeginning(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return 0;
    }

    newNode->next = *head;
    *head = newNode;
    return 0;
}

int deleteBeginning(Node** head)
{
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return 0;
}


// checking if the stack is empty?
int isEmpty(Node** stack) { 
    return *stack == NULL;
 }

// push elements to the stack
void push(Node** stack, int data)
{
   
    if (insertBeginning(stack, data)) {
        printf("Stack Overflow!\n");
    }
}

int pop(Node** stack)
{
    if (isEmpty(stack)) { //check underflow
        printf("Stack Underflow\n");
        return -1;
    }

    deleteBeginning(stack); //removing the head
}

int peek(Node** stack)
{
    // checking for empty stack
    if (!isEmpty(stack))
        return (*stack)->data;
    else
        return -1;
}

void printStack(Node** stack)
{
    Node* temp = *stack;
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node* stack = NULL; // init the stack pointer
    int choice, value;

    while (1) {
        printf("\n ********** Stack Menu **********\n");
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
            if (!isEmpty(&stack)) {
                int topValue = peek(&stack);
                pop(&stack);
                printf("Popped value: %d\n", topValue);
            } else {
                printf("Stack Underflow! Nothing to pop.\n");
            }
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
            // clearing and freeing all nodes before closing
            while (!isEmpty(&stack))
                pop(&stack);
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
