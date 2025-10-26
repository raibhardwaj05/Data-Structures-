#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// insert at end
node *insert_end(node *head)
{
    node *temp, *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("Enter Data: ");
    scanf("%d", &newnode->data);

    temp = head;
    if (head == NULL)
    {
        printf("\nNo nodes created...inserting at beginning");
        head = temp = newnode;
        newnode->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        temp->next = newnode;
    }

    return head;
}