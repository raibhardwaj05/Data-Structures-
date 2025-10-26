#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
    struct node *prev; // self referencing structure
} node;

// delete first node
node *delete_first(node *head)
{
    node *temp;

    temp = head;

    if (head == NULL)
    {
        printf("\nList Empty!\n");
    }
    else
    {
        head = head->next;

        // if list was of only one node then head = head->next will be null
        if (head != NULL)
        {
            head->prev = NULL;
        }

        free(temp);
    }
    return head;
}