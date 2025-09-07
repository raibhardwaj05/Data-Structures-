#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
    struct node *prev; // self referencing structure
} node;

// display the list
void display(node *head)
{
    node *temp;
    temp = head;

    if (head == NULL)
    {
        printf("\nNo Node is created");
    }
    else
    {
        printf("\nData in the nodes: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}