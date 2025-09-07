#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
    struct node *prev; // self referencing structure
} node;

// reverse display the list
void Reverse_display(node *head)
{
    node *temp, *last = NULL;
    temp = head;

    if (head == NULL)
    {
        printf("\nNo Node is created");
    }
    else
    {
        while (temp != NULL)
        {
            last = temp;
            temp = temp->next;
        }

        printf("\nReversed Data in the nodes: ");
        while (last != NULL)
        {   
            printf("%d ", last->data);
            last = last->prev;
        }
        printf("\n");
    }
}