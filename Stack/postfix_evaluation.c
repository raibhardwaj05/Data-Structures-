#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int stack[50];
int top = -1;

void push(char x){
    if (top == 49)
    {
        printf("stack full");
        return;
    }

    stack[++top] = x;   
}

char pop(){
    if (top == -1)
    {
        printf("Staqck empty");
        return -1;
    }

    return stack[top--]; 
    
}

char stacktop(){
    return stack[top];
}

int operate(char op, int num1, int num2){
    switch (op)
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
    default: printf("invalid");
            return 0;
    }
    
}

void evaluate(char postfix[50]){
    int i, first_num, second_num, result = 0;
    
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else{
            second_num = pop();
            first_num = pop();

            result = operate(postfix[i], first_num, second_num);
            push(result);
        }
        
    }

    result = pop();
    printf("result: %d", result);
    
}

void main(){
    char postfix[50];

    printf("enter postfix: ");
    scanf("%s", postfix);

    evaluate(postfix);
}