#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int queue[5];
int f = -1;
int r = -1;

void enqueue(){
    int val;
    printf("\nvalue: ");
    scanf("%d", &val);

    if (r == 4)
    {
        printf("\nqueue full");
        return;
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        queue[r] = val;
        return;
    }

    queue[++r] = val;
    
}

void dequeue(){
    if (f == -1)
    {
        printf("\nQueue empty");
        return;
    }
    else if (f == r)
    {
        printf("\nlast element: %d", queue[f]);
        f = r = -1;
        return;
    }

    printf("\ndequeue: %d", queue[f++]);
    
}

void main(){
   enqueue(); 
   enqueue();
   enqueue();
   enqueue();
   enqueue();
   enqueue(); // full

   dequeue();
   dequeue();
   dequeue();
   dequeue();
   dequeue();
   dequeue(); //empty

}