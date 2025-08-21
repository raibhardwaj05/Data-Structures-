#include <stdio.h>
#include <stdbool.h>

// Insertion
int insertion(int arr[], int usize, int tsize)
{
    int choice, location, data;

    if (usize >= tsize)
    {
        printf("\nArray is full");
        return usize;
    }

    printf("\nOrder of element matters? (No: 0 /Yes: 1):");
    scanf("%d", &choice);

    printf("\nEnter the location: ");
    scanf("%d", &location);

    if (location < 0 || location > usize)
    {
        printf("Invalid location");
        return usize;
    }

    printf("\nEnter the data: ");
    scanf("%d", &data);

    switch (choice)
    {
    case 1:
        // shifting elements ==>> order matters
        for (int i = usize; i > location; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[location] = data;
        usize++;

        break;
    case 0:
        // shifting not required ==>> order doesn't matter
        arr[usize] = arr[location];
        arr[location] = data;
        usize++;

        break;

    default:
        printf("\nWrong Input!");
        break;
    }

    return usize;
}

// deletion
int deletion(int arr[], int usize)
{
    int choice, location;

    if (usize == 0)
    {
        printf("\nArray is Empty");
        return usize;
    }

    printf("\nOrder of element matters? (No: 0 /Yes: 1):");
    scanf("%d", &choice);

    printf("\nEnter the location: ");
    scanf("%d", &location);

    if (location < 0 || location >= usize)
    {
        printf("Invalid location");
        return usize;
    }

    switch (choice)
    {
    case 1:
        // shifting elements ==>> order matters
        for (int i = location; i < usize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        usize--;

        break;
    case 0:
        // shifting not required ==>> order doesn't matter
        arr[location] = arr[usize - 1];
        usize--;

        break;

    default:
        printf("\nWrong Input!");
        break;
    }

    return usize;
}

// Traversal
void traversal(int arr[], int usize)
{
    if (usize == 0)
    {
        printf("\nArray is Empty");
    }
    else
    {
        printf("\nElements in array: ");
        for (int i = 0; i < usize; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int tsize = 100, usize = 4;

    int arr[100] = {1, 2, 6, 78};

    int choice;
    bool cont = true;

    while (cont)
    {

        printf("\n1.Insertion\n2.Deletion\n3.Traversal\n4.Exit\nYour Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            usize = insertion(arr, usize, tsize);
            break;

        case 2:
            usize = deletion(arr, usize);
            break;

        case 3:
            traversal(arr, usize);
            break;

        case 4:
            cont = false;
            break;

        default:
            printf("Do you want to continue? (0/1): ");
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