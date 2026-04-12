#include <stdio.h>
#include <stdlib.h>


int main() {
    double a, b, answer;
    char op;
    
    printf("Enter first number:\n");
    scanf("%lf", &a);

    printf("Enter operator (+ - * /):\n");
    scanf(" %c", &op);

    printf("Enter second number:\n");
    scanf("%lf", &b);

    if (op == '+') {
        answer = a + b;
    }
    else if (op == '-') {
        answer = a - b;
    }
    else if (op == '*') {
        answer = a * b;
    }
    else if (op == '/') {
        answer = a / b;
    }
    else {
        printf("Invalid operator\n");
        return 0;
    }

    printf("Answer: %lf\n", answer);

    return 0;
}

