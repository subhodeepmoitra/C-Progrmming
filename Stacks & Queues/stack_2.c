#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct Process {
    char name[50];
    int ID;
};

struct Stack {
    struct Process arr[MAX];
    int top;
};

void initializeStack(struct Stack * stack);
int isEmpty(struct Stack stack);
int isFull(struct Stack stack);
void push(struct Stack * stack, struct Process process);
struct Process pop(struct Stack * stack);
struct Process peek(struct Stack stack);
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

void push(struct Stack * stack, struct Process process){
    if(isFull(*stack)){
        printf("Stack Overflow");
    } else {
        stack->top++;
        strncpy(stack->arr[stack->top].name, process.name, 49);
        stack->arr[stack->top].name[49]='\0';
        stack->arr[stack->top].ID = process.ID;
        printf("Pushed %s %d successfully\n", process.name, process.ID);
    }
}

struct Process pop(struct Stack * stack){
    struct Process emptyProcess = {"",-1};
    if (isEmpty(*stack))
    {
        printf("Underflow\n");
        return emptyProcess;
    } else {
        struct Process data = stack->arr[stack->top];
        stack->top--;
        return data;
    }

}

struct Process peek(struct Stack stack){
    struct Process emptyProcess = {"",-1};
    if (isEmpty(stack))
    {
        printf("Stack empty\n");
        return emptyProcess;
    } else {
        return stack.arr[stack.top];
    }
    
    
}

void display(struct Stack stack){
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
    } else {
        printf("Elements are: \n");
        for (int i = stack.top; i >= 0; i--)
        {
            printf("Process ID: %d Process Name: %s \n",stack.arr[i].ID, stack.arr[i].name);
        }
        
    }
    
}

int main(){
    int choice, data;
    struct Stack stack;
    struct Process process;
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
            printf("Enter process name: ");
            scanf("%s",process.name);
            printf("Enter process ID: ");
            scanf("%d",&process.ID);
            push(&stack,process);
            break;

        case 2:
            process = pop(&stack);
            if (process.ID != -1)
            {
                printf("Popped process %s %d successfully\n", process.name, process.ID);
            }
            break;

        case 3:
            process = peek(stack);
            if (process.ID != -1)
            {
                printf("Top process is %s %d \n", process.name, process.ID);
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