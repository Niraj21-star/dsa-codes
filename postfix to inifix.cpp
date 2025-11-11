#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return (top == -1) ? '\0' : stack[top--]; }
char peek() { return (top == -1) ? '\0' : stack[top]; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// ---------------- Infix to Postfix ----------------
void infixToPostfix(char infix[], char postfix[]) {
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c))  // operand
            postfix[j++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        } else { // operator
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

// ---------------- Postfix Evaluation ----------------
int evalPostfix(char postfix[]) {
    int valStack[MAX], valTop = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        if (isdigit(c))
            valStack[++valTop] = c - '0';  // convert char to int
        else {
            int b = valStack[valTop--];
            int a = valStack[valTop--];
            switch (c) {
                case '+': valStack[++valTop] = a + b; break;
                case '-': valStack[++valTop] = a - b; break;
                case '*': valStack[++valTop] = a * b; break;
                case '/': valStack[++valTop] = a / b; break;
                case '^': valStack[++valTop] = pow(a, b); break;
            }
        }
    }
    return valStack[valTop];
}

// ---------------- Main ----------------
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression (use single-digit numbers): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    printf("Evaluated result: %d\n", evalPostfix(postfix));

    return 0;
}
