#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
} node;

// Insert new nodes at the end
node *insert_end(node *head)
{
    node *temp, *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL; // to avoid garbage value

    printf("Enter Data: ");
    scanf("%d", &newnode->data);

    temp = head;

    if (head == NULL)
    {
        printf("\nNodes created...Inserting at beginning");
        head = temp = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    return head;
}
