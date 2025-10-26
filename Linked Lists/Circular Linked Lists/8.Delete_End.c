#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// Delete last
node *delete_end(node *head)
{
    node *temp, *denode;

    temp = head;

    if (head == NULL)
    {
        printf("\nNo nodes created");
    }
    else if (temp->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        denode = temp->next;
        temp->next = head;
        free(denode);
    }

    return head;
}