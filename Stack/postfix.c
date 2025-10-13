#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[50];
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

int priority(char op){
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '-' || op == '+') return 1;
    
    else return 0;
}

void infix_to_postfix(char infix[50], char postfix[50]){
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else{
            if (infix[i] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (stack[top] != '(')
                {
                    postfix[j++] = pop();
                }
                if (top != -1)
                {
                    pop();
                }
                
                
            }
            else{
                if (top != -1 && priority(infix[i]) <= priority(stacktop()))
                {
                    postfix[j++] = pop();
                }
                push(infix[i]);
            
            }
            
            
        }

        
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j++] = '\0';
    
}

void main(){
    char infix[50], postfix[50];

    printf("Enter infix: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix: %s", postfix);
}