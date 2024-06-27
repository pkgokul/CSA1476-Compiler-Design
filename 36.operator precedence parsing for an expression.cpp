#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Define precedence levels
int precedence(*char operator);
{
    switch (operator) {
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

// Define associativity of operators
int is_right_associative(char operator) {
    if (operator == '^')
        return 1;
    return 0;
}

// Check if character is an operator
int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Perform the actual operator precedence parsing
void operator_precedence_parsing(char *expression) {
    char stack[MAX];
    int top = -1;
    char output[MAX];
    int output_index = 0;

    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            output[output_index++] = expression[i];
        } else if (is_operator(expression[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(expression[i]) && !is_right_associative(expression[i])) {
                output[output_index++] = stack[top--];
            }
            stack[++top] = expression[i];
        }
    }

    while (top != -1) {
        output[output_index++] = stack[top--];
    }

    output[output_index] = '\0';

    printf("Parsed expression (Postfix notation): %s\n", output);
}

int main() {
    char expression[MAX];

    printf("Enter the expression: ");
    scanf("%s", expression);

    operator_precedence_parsing(expression);

    return 0;
}


