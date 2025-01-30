#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define maxsize 50

typedef struct {
    int top;
    char arr[maxsize];
} stack;

void push(char x, stack *s) {
    if (s->top == maxsize - 1) {
        printf("\nStack is full...");
        return;
    }
    s->arr[++(s->top)] = x;
}

char peek(stack *s) {
    if (s->top == -1) {
        return -1;
    }
    return s->arr[s->top];
}

char pop(stack *s) {
    if (s->top == -1) {
        printf("\nStack is empty...");
        return -1;
    }
    return s->arr[(s->top)--];
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void convert(char infix[], char postfix[]) {
    stack s;
    s.top = -1;
    char x;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        x = infix[i];
        if (isdigit(x) || isalpha(x)) {
            postfix[j++] = x;
        } else if (x == '(') {
            push(x, &s);
        } else if (x == ')') {
            while ((x = pop(&s)) != '(') {
                postfix[j++] = x;
            }
        } else if (isOperator(x)) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(x)) {
                postfix[j++] = pop(&s);
            }
            push(x, &s);
        }
        i++;
    }
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[maxsize], postfix[maxsize];
    printf("\nEnter infix expression: ");
    scanf("%s",infix);
    convert(infix, postfix);
    printf("\nPostfix expression is: %s", postfix);
    return 0;
}
