#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// structure to make a custom array (BLUEPRINT)
struct myArray
{
    // total size to be reverved
    int total_size;

    // total size to be used
    int used_size;

    // int ptr pointing to the 1st element of the array
    int *element1_ptr;
};

// struct myArray *struct_add → means we pass the address of a struct variable marks
void createArray(struct myArray *struct_add, int tsize, int usize)
{

    // (*struct_add).total_size = tsize;
    // (*struct_add).used_size = usize;
    // (*struct_add).element1_ptr = (int *)malloc(tsize * sizeof(int));

    // ptr = malloc(N * sizeof(int)) → reserves space for N integers
    struct_add->total_size = tsize;
    struct_add->used_size = usize;
    struct_add->element1_ptr = (int *)malloc(tsize * sizeof(int));
}

void setValue(struct myArray *array)
{
    int n;
    for (int i = 0; i < array->used_size; i++)
    {
        printf("Enter element %d: ", (i + 1));
        scanf("%d", &n);
        (array->element1_ptr)[i] = n;
    }
}

void show(struct myArray *array)
{

    printf("values:\n");
    for (int i = 0; i < array->used_size; i++)
    {
        printf("%d\n", (array->element1_ptr)[i]);
    }
}

void get_data(struct myArray *array)
{
    int location;
    printf("Enter the location: ");
    scanf("%d", &location);

    if (location < 0 || location >= array->used_size)
    {
        printf("invalid location");
        return;
    }
    else
    {
        printf("data at %d: %d\n", location, (array->element1_ptr)[location]);
    }
}

// inserts element in the array at a given location
void insert_at_location(struct myArray *array)
{
    // array is full
    if (array->used_size >= array->total_size)
    {
        printf("Array is full");
        return;
    }

    int location;
    printf("Enter the location: ");
    scanf("%d", &location);

    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    for (int i = array->used_size; i > location; i--)
    {
        array->element1_ptr[i] = array->element1_ptr[i - 1];
    }

    array->element1_ptr[location] = val;
    array->used_size++;
}

// change the data that already exist at that location
void update_data(struct myArray *array)
{
    int location;
    printf("Enter the location: ");
    scanf("%d", &location);

    if (location < 0 || location >= array->used_size)
    {
        printf("Invalid location");
        return;
    }
    else
    {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        array->element1_ptr[location] = data;
    }
}

int main()
{
    struct myArray marks;
    int choice;
    bool cont = true;
    createArray(&marks, 10, 2);

    while (cont)
    {

        printf("\n1.Set Values\n2.Show Values\n3.Get values from any location\n4.Update Value at any Location\n5.Insert at any Location\nYour Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            setValue(&marks);
            break;

        case 2:
            show(&marks);
            break;

        case 3:
            get_data(&marks);
            break;

        case 4:
            update_data(&marks);
            break;

        case 5:
            insert_at_location(&marks);
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