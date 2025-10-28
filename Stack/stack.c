#include<stdio.h>

int stack[10];
int top = -1;

void push(int data){
    if (top == 9)
    {
        printf("\nstack full");
    }
    else{
        stack[++top] = data;
    }
    
}

void pop(){
    if (top == -1)
    {
        printf("\nstack empty");
        return;
    }
    
    printf("\n%d ", stack[top--]);
}

void stackTop(){
    if (top == -1)
    {
        printf("\nStack empty");
    }
    else{
        printf("\n%d ", stack[top]);
    }
    
}

void display(){
    if (top == -1)
    {
        printf("\nStack empty");
    }
    else{
        int i = top;
        printf("\nElement are: ");

        while (i > -1)
        {
            printf("%d ", stack[i]);
            i--;
        }
    }
}


int main(){
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    display();

    return 0;
}
