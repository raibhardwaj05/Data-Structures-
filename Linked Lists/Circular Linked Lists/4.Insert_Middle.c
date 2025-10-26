#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// insert at a location
node *insert_middle(node *head)
{
    node *temp, *newnode;
    int loc;

    printf("\nEnter location: ");
    scanf("%d", &loc);

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    temp = head;
    if (head == NULL)
    {
        printf("\nNo nodes created...Inserting at beginning");
        head = temp = newnode;
        newnode->next = head;
    }
    else
    {
        int i;

        if (loc == 1)
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->next = head;
            head = newnode;

            return head;
        }
        else
        {
            for (i = 1; i < loc - 1 && temp->next != head; i++)
            {
                temp = temp->next;
            }

            if (i != loc - 1)
            {
                printf("\nLocation not found");
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    return head;
}