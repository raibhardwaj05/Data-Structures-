#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
    struct node *prev; // self referencing structure
} node;

// insert node at middle
node *insert_middle(node *head)
{
    node *temp, *newnode;
    int location;
    printf("\nEnter Location: ");
    scanf("%d", &location);

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);

    temp = head;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        if (location == 1)
        {
            newnode->next = temp;
            temp->prev = newnode;
            head = newnode;
        }
        else
        {
            int i;
            for (i = 1; i < (location - 1) && temp != NULL; i++)
            {
                temp = temp->next;
            }

            if (i < (location - 1))
            {
                printf("\nLocation is beyond length, inserting at end");
            }

            newnode->next = temp->next;
            newnode->prev = temp;

            // this avoids the segmentation error ie if temp->next is NULL then error will occur
            if (temp->next != NULL)
            {
                temp->next->prev = newnode;
            }

            temp->next = newnode;
        }
    }

    return head;
}