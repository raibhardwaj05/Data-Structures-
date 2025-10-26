#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// delete first
node *delete_first(node *head)
{
    node *denode, *temp;

    if (head == NULL)
    {
        printf("\nNo nodes created");
        return head;
    }

    denode = head;

    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nOnly node deleted. List is now empty.\n");
        return head;
    }
    else
    {
        temp = head->next;

        head = temp;

        while (temp->next != denode)
        {
            temp = temp->next;
        }

        temp->next = head;
    }

    free(denode);

    return head;
}