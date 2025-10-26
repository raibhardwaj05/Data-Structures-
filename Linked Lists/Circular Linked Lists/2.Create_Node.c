#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// create node
node *create_node(node *head)
{
    node *temp, *newnode;
    int num_nodes;

    printf("\nEnter number of nodes: ");
    scanf("%d", &num_nodes);

    printf("\n");
    while (num_nodes > 0)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;

        printf("Enter Data: ");
        scanf("%d", &newnode->data);

        temp = head;
        if (head == NULL)
        {
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

        num_nodes--;
    }

    return head;
}