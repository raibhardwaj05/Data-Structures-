#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
    struct node *prev; // self referencing structure
} node;

// insert node at first
node *insert_first(node *head)
{
    node *temp, *newnode;

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
        temp->prev = newnode;
        newnode->next = temp;
        head = newnode;
    }

    return head;
}