#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
} node;

node *create_node(node *head)
{
    node *temp, *newnode;
    int num_nodes;

    printf("\nNumber of nodes to be created: ");
    scanf("%d", &num_nodes);

    while (num_nodes > 0)
    {

        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL; // to avoid garbage value

        printf("Enter Data: ");
        scanf("%d", &newnode->data);

        temp = head;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        num_nodes--;
    }

    return head;
}

node *insert_middle(node *head){
    node *temp, *newnode;

    int location;
    printf("\nEnter the location: ");
    scanf("%d", &location);

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    temp = head;

    if (head == NULL)
    {
        head = temp = newnode;
        printf("\nThis is 1st node created!");
    }
    else{
        if (location == 1)
        {
            printf("\nCreating node at 1st place");
            newnode->next = head;
            head = newnode;
        }
        else{
            int i;
            for (i = 1; i < location - 1 && temp != NULL; i++)
            {
                temp = temp->next;
            }

            if (i < location - 1)
            {
                printf("\nLocation is beyond length, inserting at end");
            }
            
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    return head;
    
}

void display(node *head)
{
    node *temp;
    temp = head;

    if (head == NULL)
    {
        printf("\nNo Node is created");
    }
    else
    {
        printf("\nData in the nodes: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        
    }
}

int main()
{
    struct node *head;
    head = NULL;
    int choice;
    bool cont = true;

    while (cont)
    {

        printf("\n1.Create New Node\n2.Show Values\n3.Insert In Between\nYour Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create_node(head);
            break;

        case 2:
            display(head);
            break;

        case 3:
            head = insert_middle(head);
            break;

        case 4:

            break;

        case 5:

            break;

        default:
            printf("\nDo you want to continue? (0/1): ");
            scanf("%d", &choice);

            if (choice == 0)
            {
                cont = false;
            }

            break;
        }
    }
    return 0;
}