#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 20

int top = -1;
int s[MAX_SIZE];

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s[top--];
}

int evaluatePostfix(char postfix[]) {
    int i, op1, op2;
    char symb;

    for (i = 0; postfix[i] != '\0'; i++) {
        symb = postfix[i];
        if (isdigit(symb)) {
            push(symb - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (symb) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Division by zero\n");
                        return 0;
                    }
                    push(op1 / op2);
                    break;
                case '^':
                    // Implementing exponentiation with a loop
                    int result = 1;
                    for (int j = 0; j < op2; j++) {
                        result *= op1;
                    }
                    push(result);
                    break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    if (result != -1)
        printf("Result: %d\n", result);
    return 0;
}
