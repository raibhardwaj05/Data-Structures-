#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// Create circular linked list with given nodes
node *create(node *head)
{
    printf("\nCreate nodes");
    node *temp, *newnode;
    int nodes;

    printf("\nEnter number of nodes: ");
    scanf("%d", &nodes);

    while (nodes > 0)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;

        printf("\nEnter data: ");
        scanf("%d", &newnode->data);

        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }

        nodes--;
    }

    return head;
}

// Insert node at beginning of circular linked list
node *insertBegin(node *head)
{
    printf("\nInsert at beginning");
    node *newnode, *temp;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    // If list is empty, new node points to itself
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return head;
    }

    // Otherwise, find last node to update next pointer
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
    head = newnode;

    return head;
}

// Insert node after the node with specified value
node *middle(node *head)
{
    printf("\nInsert in middle");

    if (head == NULL)
    {
        printf("\nList is empty, cannot insert in middle.\n");
        return head;
    }

    int val;
    printf("\nEnter value after which to insert: ");
    scanf("%d", &val);

    node *temp = head;
    node *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("\nEnter new node data: ");
    scanf("%d", &newnode->data);

    // Traverse to find node with data = val
    do
    {
        if (temp->data == val)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    printf("\nValue %d not found in the list.\n", val);
    free(newnode);
    return head;
}

// Display circular linked list
void display(node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nDisplay list:\n");
    node *temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    node *head = NULL;

    head = create(head);
    head = insertBegin(head);
    head = middle(head);

    display(head);

    return 0;
}
