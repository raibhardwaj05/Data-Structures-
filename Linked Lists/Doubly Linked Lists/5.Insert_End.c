#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
    struct node *prev; // self referencing structure
} node;

// Insert new nodes at the end
node *insert_end(node *head)
{
    node *temp, *newnode;

    temp = head;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        printf("\nNo Nodes Created...Inserting at beginning");
        head = temp = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newnode->prev = temp;
        temp->next = newnode;
    }

    return head;
}