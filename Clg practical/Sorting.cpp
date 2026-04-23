#include <iostream>
using namespace std;

// display
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// -----------------------------------insertion sort--------------------------------------
void insertion(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ------------------------------------quick sort--------------------------------------
// partition index
int pivot(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        // i travels right until it gets element greater than pivot
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }

        // j travels left until it gets element lesser than pivot
        while (j >= low && arr[j] > pivot)
        {
            j--;
        }

        // i and j cross each other
        if (i < j)
        {
            // swap when arr[i] > pivot and arr[j] < pivot but i and j have not yet crossed each other  
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap when pivot and arr[j] cross each other ==> place the pivot at it's correct place
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    // partition index
    return j;
}
// quick sort recursive calls
void quick_sort(int arr[], int low, int high)
{
    // base condition
    if (low >= high)
        return;

    // get the partition index and pivot
    int partition_index = pivot(arr, low, high);

    // left unsorted array
    quick_sort(arr, low, partition_index - 1);

    // right unsorted array
    quick_sort(arr, partition_index + 1, high);
}

// --------------------------------------main------------------------------------------
int main()
{
    int arr[] = {3, 2, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "before sorting: ";
    display(arr, size);

    // insertion(arr, size);
    quick_sort(arr, 0, size - 1);

    cout << "after sorting: ";
    display(arr, size);

    return 0;
}