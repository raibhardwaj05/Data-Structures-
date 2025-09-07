#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
} node;

// insert node at first
node *insert_first(node *head){
    node *temp, *newnode;
    int data;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    temp = head;

    if (head == NULL)
    {
        printf("\nCreating first node!\n");
        head = temp = newnode;
    }
    else{
        newnode->next = temp;
        head = newnode;
    }

    return head;
}