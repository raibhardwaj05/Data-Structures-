#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
} node;

// delete last node
node *delete_end(node *head){
    node *temp, *denode;

    temp = head;
    denode = head->next;

    if (head == NULL)
    {
        printf("\nList Empty\n");
        return head;
    }
    else if(head->next == NULL) {
        free(head);
        return NULL;
    }
    else {
        while (denode->next != NULL)
        {
            temp = denode;
            denode = denode->next;
        }

        temp->next = NULL;
        free(denode);        
    }

    return head;
}