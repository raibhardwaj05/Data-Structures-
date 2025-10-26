#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// delete from a location
node *delete_middle(node *head)
{
    node *temp, *denode;

    int loc;
    printf("Enter location to delete: ");
    scanf("%d", &loc);

    temp = head;

    if (head == NULL)
    {
        printf("\nNo nodes created");
    }
    else if (loc == 1)
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
            printf("\nOnly node deleted. List is now empty.\n");
            return head;
        }

        denode = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        head = head->next;
        temp->next = head;
        free(denode);
    }
    else
    {
        int i;
        for (i = 1; i < loc - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }

        denode = temp->next;
        temp->next = denode->next;
        free(denode);
    }

    return head;
}