#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// create node
node *create_node(node *head)
{
    node *temp, *newnode;
    int num_nodes;

    printf("\nEnter number of nodes: ");
    scanf("%d", &num_nodes);

    printf("\n");
    while (num_nodes > 0)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;

        printf("Enter Data: ");
        scanf("%d", &newnode->data);

        temp = head;
        if (head == NULL)
        {
            head = temp = newnode;
            newnode->next = head;
        }
        else
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }

            newnode->next = head;
            temp->next = newnode;
        }

        num_nodes--;
    }

    return head;
}

// insert in the beginning
node *insert_first(node *head)
{
    node *temp, *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    temp = head;
    if (head == NULL)
    {
        printf("\nNo nodes created...Inserting at beginning");
        head = temp = newnode;
        newnode->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }

    return head;
}

// insert at a location
node *insert_middle(node *head)
{
    node *temp, *newnode;
    int loc;

    printf("\nEnter location: ");
    scanf("%d", &loc);

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    temp = head;
    if (head == NULL)
    {
        printf("\nNo nodes created...Inserting at beginning");
        head = temp = newnode;
        newnode->next = head;
    }
    else
    {
        int i;

        if (loc == 1)
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->next = head;
            head = newnode;

            return head;
        }
        else
        {
            for (i = 1; i < loc - 1 && temp->next != head; i++)
            {
                temp = temp->next;
            }

            if (i != loc - 1)
            {
                printf("\nLocation not found");
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    return head;
}

// insert at end
node *insert_end(node *head)
{
    node *temp, *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;

    printf("Enter Data: ");
    scanf("%d", &newnode->data);

    temp = head;
    if (head == NULL)
    {
        printf("\nNo nodes created...inserting at beginning");
        head = temp = newnode;
        newnode->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        temp->next = newnode;
    }

    return head;
}

// delete first
node *delete_first(node *head)
{
    node *denode, *temp;

    if (head == NULL)
    {
        printf("\nNo nodes created");
        return head;
    }

    denode = head;

    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nOnly node deleted. List is now empty.\n");
        return head;
    }
    else
    {
        temp = head->next;

        head = temp;

        while (temp->next != denode)
        {
            temp = temp->next;
        }

        temp->next = head;
    }

    free(denode);

    return head;
}

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

// Delete last
node *delete_end(node *head)
{
    node *temp, *denode;

    temp = head;

    if (head == NULL)
    {
        printf("\nNo nodes created");
    }
    else if (temp->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        denode = temp->next;
        temp->next = head;
        free(denode);
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
        printf("\nNo Nodes created");
    }
    else
    {
        printf("\nData: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
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

        printf("\n1.Create_NewNode\n2.Display\n3.Insert_Between\n4.Insert_First\n5.Delete_First\n6.Delete_Middle\n7.Delete_Last\n8.Insert_End\nYour Choice: ");
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
