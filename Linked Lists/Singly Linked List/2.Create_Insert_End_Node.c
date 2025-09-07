#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
} node;

// Create nodes OR Insert new nodes at the end
node *create_node_insert_end(node *head)
{
    node *temp, *newnode;
    int num_nodes;

    printf("\nNumber of nodes to be created: ");
    scanf("%d", &num_nodes);

    while (num_nodes > 0)
    {

        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL; // to avoid garbage value

        printf("Enter Data: ");
        scanf("%d", &newnode->data);

        temp = head;

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
            temp->next = newnode;
        }

        num_nodes--;
    }

    return head;
}