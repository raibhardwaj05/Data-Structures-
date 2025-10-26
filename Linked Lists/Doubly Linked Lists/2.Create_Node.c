#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
    struct node *prev; // self referencing structure
} node;

// Create nodes
node *create_node(node *head)
{
    node *temp, *newnode;
    int num_nodes;

    printf("\nNumber of nodes?: ");
    scanf("%d", &num_nodes);

    while (num_nodes > 0)
    {
        temp = head;

        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->prev = NULL;

        printf("\nEnter Data: ");
        scanf("%d", &newnode->data);

        if (head == NULL)
        {
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
        num_nodes--;
    }

    return head;
}