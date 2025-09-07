#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

int isEmpty(struct Stack stack);
int isFull(struct Stack stack);
void push(struct Stack * stack, char data);
char pop(struct Stack * stack);
char peek(struct Stack stack);
int getPriority(char ch);
void infix2postfix(char s[], char t[]);

int isFull(struct Stack stack) {
    return stack.top == MAX - 1;
}

int isEmpty(struct Stack stack) {
    return stack.top == -1;
}

void push(struct Stack * stack, char data) {
    
    stack->top++;
    stack->arr[stack->top] = data;
}

char pop(struct Stack * stack) {
   
    char data = stack->arr[stack->top];
    stack->top--;
    return data;
}

char peek(struct Stack stack) {
   
    return stack.arr[stack.top];
}

int getPriority(char ch) {
    if (ch == '+' || ch == '-') {
        return 0;
    } else {
        return 1;
    }
}

void infix2postfix(char s[], char t[]) {
    struct Stack st;
    st.top = -1;
    int i = 0, j = 0;

   while (s[i] != '\0') { // Loop until null character is encountered

    // Checking (
    if (s[i] == '(') {
        push(&st, s[i]);
    }

    // Check )
    if (s[i] == ')') {
        while (peek(st) != '(') {
            t[j++] = pop(&st);
        }
        pop(&st); // Pop the '('
    }

    // Checking if the current char is num. or dig.
    if (isalpha(s[i]) || isdigit(s[i])) {
        t[j++] = s[i];
    }

    // Checking if the current char is operator -> if 'yes' then check priority
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%') {
        while (!isEmpty(st) && peek(st) != '(' && getPriority(peek(st)) >= getPriority(s[i])) {
            t[j++] = pop(&st);
        }
        push(&st, s[i]);
    }

    i++; // Moving to next char
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