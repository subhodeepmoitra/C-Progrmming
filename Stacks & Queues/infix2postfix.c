#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void initializeStack(struct Stack * stack);
int isEmpty(struct Stack stack);
int isFull(struct Stack stack);
void push(struct Stack * stack, char data);
char pop(struct Stack * stack);
char peek(struct Stack stack);
int getPriority(char ch);
void infix2postfix(char s[], char t[]);

void initializeStack(struct Stack * stack) {
    stack->top = -1;
}

int isFull(struct Stack stack) {
    return stack.top == MAX - 1;
}

int isEmpty(struct Stack stack) {
    return stack.top == -1;
}

void push(struct Stack * stack, char data) {
    if (isFull(*stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

char pop(struct Stack * stack) {
    if (isEmpty(*stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    char data = stack->arr[stack->top];
    stack->top--;
    return data;
}

char peek(struct Stack stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack.arr[stack.top];
}

int getPriority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0; //the default priority for brackets
}

void infix2postfix(char s[], char t[]) {
    struct Stack st;
    initializeStack(&st);
    int i = 0, j = 0;

    while (s[i] != '\0') { //looping till null character is received
        if (isalnum(s[i])) {
            t[j++] = s[i];
        }

        if (s[i] == '(') {
            push(&st, s[i]);
        }

        if (s[i] == ')') {
            while (!isEmpty(st) && peek(st) != '(') {
                t[j++] = pop(&st);
            }
            if (!isEmpty(st) && peek(st) == '(') {
                pop(&st);
            }
        }

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%') {
            while (!isEmpty(st) && peek(st) != '(' && getPriority(peek(st)) >= getPriority(s[i])) { //checking proprity
                t[j++] = pop(&st);
            }
            push(&st, s[i]);
        }
        i++;
    }

    while (!isEmpty(st)) {
        t[j++] = pop(&st);
    }
    t[j] = '\0'; //null terminating postfix expression string
}

int main() {
    char infix_expression[MAX];
    char postfix_expression[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix_expression); 

    printf("Infix expression: %s\n", infix_expression);
    infix2postfix(infix_expression, postfix_expression);
    printf("Postfix expression: %s\n", postfix_expression);
    
    return 0;
}