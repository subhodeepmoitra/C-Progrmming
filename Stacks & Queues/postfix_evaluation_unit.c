#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} IntStack;


int isEmptyInt(IntStack stack);
void pushInt(IntStack *stack, int data);
int popInt(IntStack *stack);
int evaluatePostfix(char postfix[]);


int isEmptyInt(IntStack stack) {
    return stack.top == -1;
}

void pushInt(IntStack *stack, int data) {
     stack->top++;
     stack->arr[stack->top] = data;
}

int popInt(IntStack *stack) {
    int data = stack->arr[stack->top];
    stack->top--;
    return data;
}

int evaluatePostfix(char postfix[]) {
    IntStack st;
    st.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            pushInt(&st, postfix[i] - '0'); 
        } else {
            int val2 = popInt(&st);
            int val1 = popInt(&st);
            int result;

            if (postfix[i] == '+') {
                result = val1 + val2;
            } else if (postfix[i] == '-') {
                result = val1 - val2;
            } else if (postfix[i] == '*') {
                result = val1 * val2;
            } else if (postfix[i] == '/') {
                result = val1 / val2;
            } else if (postfix[i] == '%') {
                result = val1 % val2;
            } else {
                printf("Invalid...\n");
                exit(1);
            }

            pushInt(&st, result);
        }
    }

    return popInt(&st);
}

int main() {
     
    char postfix_expression[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix_expression); 

    /* Test Cases
    23+ -> 5
    23*54*+ -> 26
    82/ -> 4
    */

    printf("Postfix expression: %s\n", postfix_expression);

    int result = evaluatePostfix(postfix_expression);
    printf("Evaluation result: %d\n", result);

    return 0;
}