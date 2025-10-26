#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // self referencing structure
    struct node *prev; // self referencing structure
} node;

// Insert new nodes at the end
node *insert_end(node *head)
{
    node *temp, *newnode;

    temp = head;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        printf("\nNo Nodes Created...Inserting at beginning");
        head = temp = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newnode->prev = temp;
        temp->next = newnode;
    }

    return head;
}

// Create nodes
node *create_node(node *head)
{
    node *temp, *newnode;
    int num_nodes;

    printf("\nNumber of nodes?: ");
    scanf("%d", &num_nodes);

    while (num_nodes > 0)
    {
        temp = head;

        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->prev = NULL;

        printf("\nEnter Data: ");
        scanf("%d", &newnode->data);

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

            newnode->prev = temp;
            temp->next = newnode;
        }
        num_nodes--;
    }

    return head;
}

// insert node at first
node *insert_first(node *head)
{
    node *temp, *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);

    temp = head;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->prev = newnode;
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
    printf("\nEnter Location: ");
    scanf("%d", &location);

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);

    temp = head;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        if (location == 1)
        {
            newnode->next = temp;
            temp->prev = newnode;
            head = newnode;
        }
        else
        {
            int i;
            for (i = 1; i < (location - 1) && temp != NULL; i++)
            {
                temp = temp->next;
            }

            if (i < (location - 1))
            {
                printf("\nLocation is beyond length, inserting at end");
            }

            newnode->next = temp->next;
            newnode->prev = temp;

            // this avoids the segmentation error ie if temp->next is NULL then error will occur
            if (temp->next != NULL)
            {
                temp->next->prev = newnode;
            }

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

// reverse display the list
void Reverse_display(node *head)
{
    node *temp, *last = NULL;
    temp = head;

    if (head == NULL)
    {
        printf("\nNo Node is created");
    }
    else
    {
        while (temp != NULL)
        {
            last = temp;
            temp = temp->next;
        }

        printf("\nReversed Data in the nodes: ");
        while (last != NULL)
        {
            printf("%d ", last->data);
            last = last->prev;
        }
        printf("\n");
    }
}

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

// delete last node
node *delete_end(node *head)
{
    node *temp, *denode;

    if (head == NULL)
    {
        printf("\nList Empty!\n");
    }
    // Only one node in the list
    else if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        temp = head;
        denode = head->next;

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

        printf("\n1.Create_NewNode\n2.Display\n3.Insert_Between\n4.Insert_First\n5.Delete_First\n6.Delete_Middle\n7.Delete_Last\n8.Reverse\n9.Insert_End\nYour Choice: ");
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

        case 8:
            Reverse_display(head);
            break;
            
        case 9:
            head = insert_end(head);
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