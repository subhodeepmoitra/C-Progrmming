#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Stack {
    int arr[MAX];
    int top;
};

void initializeStack(struct Stack * stack);
int isEmpty(struct Stack stack);
int isFull(struct Stack stack);
void push(struct Stack * stack, int data);
int pop(struct Stack * stack);
int peek(struct Stack stack);
void display(struct Stack stack);

void initializeStack(struct Stack * stack){
    stack->top = -1;
}

int isFull(struct Stack stack){
    return stack.top == MAX-1;
}

int isEmpty(struct Stack stack){
    return stack.top == -1;
}

void push(struct Stack * stack, int data){
    if(isFull(*stack)){
        printf("Stack Overflow");
    } else {
        stack->top++;
        stack->arr[stack->top] = data;
        printf("Pushed %d successfully\n", data);
    }
}

int pop(struct Stack * stack){
    if (isEmpty(*stack))
    {
        printf("Underflow");
        return -1;
    } else {
        int data = stack->arr[stack->top];
        stack->top--;
        return data;
    }

}

int peek(struct Stack stack){
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack.arr[stack.top];
    }
    
}

void display(struct Stack stack){
    if (isEmpty(stack))
    {
        printf("Stack is empty");
    } else {
        printf("Elements are: \n");
        for (int i = stack.top; i >= 0; i--)
        {
            printf("%d ",stack.arr[i]);
        }
        
    }
    
}

int main(){
    int choice, data;
    struct Stack stack;
    initializeStack(&stack);
    while(1){
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. Peek \n");
        printf("4. IsEmpty check \n");
        printf("5. IsFull check \n");
        printf("6. Display Stack \n");
        printf("7. Exit \n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d",&data);
            push(&stack,data);
            break;

        case 2:
            data = pop(&stack);
            if (data != -1)
            {
                printf("Popped element %d successfully\n", data);
            }
            break;

        case 3:
            data = peek(stack);
            if (data != -1)
            {
                printf("Top data is %d \n", data);
            }
            break;

        case 4:
            if (isEmpty(stack))
            {
                printf("Empty stack\n");
            } else {
                printf("Elements are present\n");
            }
            break;

        case 5:
            if (isFull(stack))
            {
                printf("Stack Full\n");
            } else {
                printf("Stack is not full\n");
            }
            break;

        case 6:
            display(stack);
            printf("\n");
            break;

        case 7:
            printf("Quitting\n");
            exit(0);
            break;

        default:
            printf("Invalid Input \n");
            break;
        }
    }
    return 0;
}