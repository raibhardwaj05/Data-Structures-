#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
} node;

// delete first node
node *delete_first(node *head){
    node *temp;

    temp = head;

    if (head == NULL)
    {
        printf("\nList Empty\n");
    }
    else{
        head = temp->next;
        free(temp);
    }

    return head;    
}