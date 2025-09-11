#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
} node;


// delete from middle node
node *delete_middle(node *head){
    node *temp, *denode;
    int location;

    temp = head;
    denode = head->next;

    printf("\nEnter the location: ");
    scanf("%d", &location);

    if (head == NULL)
    {
        printf("\nList Empty\n");
        return head;
    }

    if (location == 1)
    {
        head = temp->next;
        free(temp);
    }
    
    else{
        int i = 2;
        for (i = 2; i < (location) && temp->next != NULL; i++)
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
        free(denode);
        
    }
    
    return head;
}