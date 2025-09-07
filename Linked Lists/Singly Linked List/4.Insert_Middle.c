#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
} node;

// insert node at middle
node *insert_middle(node *head)
{
    node *temp, *newnode;

    int location;
    printf("\nEnter the location: ");
    scanf("%d", &location);

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    temp = head;

    if (head == NULL)
    {
        head = temp = newnode;
        printf("\nThis is 1st node created!");
    }
    else
    {
        if (location == 1)
        {
            printf("\nCreating node at 1st place");
            newnode->next = head;
            head = newnode;
        }
        else
        {
            int i;
            for (i = 1; i < location - 1 && temp != NULL; i++)
            {
                temp = temp->next;
            }

            if (i < location - 1)
            {
                printf("\nLocation is beyond length, inserting at end");
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    return head;
}