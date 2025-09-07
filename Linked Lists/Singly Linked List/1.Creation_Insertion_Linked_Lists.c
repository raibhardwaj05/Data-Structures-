#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
} node;

// Create nodes OR Insert new nodes at the end
node *create_node_insert_end(node *head)
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

// insert node at middle
node *insert_middle(node *head)
{
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
    else
    {
        if (location == 1)
        {
            printf("\nCreating node at 1st place");
            newnode->next = head;
            head = newnode;
        }
        else
        {
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

// display the list
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
        for (i = 2; i < (location) && temp != NULL; i++)
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

int main()
{
    struct node *head;
    head = NULL;
    int choice;
    bool cont = true;

    while (cont)
    {

        printf("\n1.Create_NewNode / Insert_End\n2.Display\n3.Insert_Between\n4.Insert_First\n5.Delete_First\n6.Delete_Middle\n7.Delete_Last\nYour Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create_node_insert_end(head);
            break;

        case 2:
            display(head);
            break;

        case 3:
            head = insert_middle(head);
            break;

        case 4:
            head = insert_first(head);
            break;

        case 5:
            head = delete_first(head);
            break;
        
        case 6:
            head = delete_middle(head);
            break;

        case 7:
            head = delete_end(head);
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