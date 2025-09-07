#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
    struct node *prev; // self referencing structure
} node;

// delete from middle node
node *delete_middle(node *head)
{
    node *temp, *denode;
    int location;

    printf("\nEnter Location: ");
    scanf("%d", &location);

    if (head == NULL)
    {
        printf("\nList Empty!\n");
    }
    else
    {
        if (location == 1)
        {
            denode = head;
            head = head->next;

            if (head != NULL)
            {
                head->prev = NULL;
            }

            free(denode);
        }
        else
        {
            temp = head;
            denode = head->next;

            int i;
            for (int i = 2; i < location && denode != NULL; i++)
            {
                temp = denode;
                denode = denode->next;
            }

            if (denode == NULL)
            {
                printf("\nLocation not found\n");
                return head;
            }

            temp->next = denode->next;

            if (denode->next != NULL)
            {
                denode->next->prev = temp;
            }
            free(denode);
        }
    }

    return head;
}