#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct Stack {
    char arr[MAX_SIZE];
    int top;
};

void push(struct Stack* stack, char op) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = op;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    char op = stack->arr[stack->top];
    stack->top--;
    return op;
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void postfixToInfix(char* postfix) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    int len = strlen(postfix);
    char infix[MAX_SIZE];
    int i, j = 0;
    for (i = 0; i < len; i++) {
        char ch = postfix[i];
        if (isOperand(ch)) {
            push(stack, ch);
        } else {
            char op1 = pop(stack);
            char op2 = pop(stack);
            infix[j++] = '(';
            infix[j++] = op2;
            infix[j++] = ch;
            infix[j++] = op1;
            infix[j++] = ')';
            push(stack, infix[j-1]);
        }
    }
    infix[j] = '\0';
    printf("Infix expression: %s\n", infix);
}

void postfixToPrefix(char* postfix) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    int len = strlen(postfix);
    char prefix[MAX_SIZE];
    int i, j = 0;
    for (i = 0; i < len; i++) {
        char ch = postfix[i];
        if (isOperand(ch)) {
            push(stack, ch);
        } else {
            char op1 = pop(stack);
            char op2 = pop(stack);
            prefix[j++] = ch;
            prefix[j++] = op2;
            prefix[j++] = op1;
            push(stack, prefix[j-1]);
        }
    }
    prefix[j] = '\0';
    printf("Prefix expression: %s\n", prefix);
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix);
    postfixToPrefix(postfix);
    return 0;
}
