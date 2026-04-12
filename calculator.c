#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    double a, b, answer;
    char op, *end;
    
    if (argc == 4) {
        a = strtod(argv[1], &end);
        op = argv[2][0];
        b = strtod(argv[3], &end);
    }
    else
    {
        printf("Enter first number:\n");
        scanf("%lf", &a);
    
        printf("Enter operator (+ - * /):\n");
        scanf(" %c", &op);
    
        printf("Enter second number:\n");
        scanf("%lf", &b); 
    }

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

    printf("Answer: %lf %c %lf = %lf\n", a, op, b, answer);

    return 0;
}

