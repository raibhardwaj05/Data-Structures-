#include <iostream>
using namespace std;

void binarySearch(int arr[], int start, int end, int num)
{
    // while searching if start exceeds end then element not found
    if (start > end)
    {
        cout << "Number not found" << endl;
        return;
    }

    // get the center
    int mid = (start + end) / 2;

    if (arr[mid] == num)
    {
        cout << "Number found at mid " << mid << endl;
        return;
    }
    else if (num > arr[mid])
    {
        binarySearch(arr, mid + 1, end, num);
    }
    else
    {
        binarySearch(arr, start, mid - 1, num);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 0;
    int x = 4;

    while (x > 0)
    {
        cout << "Enter number to find ";
        cin >> num;

        binarySearch(arr, 0, size - 1, num);

        x--;
    }

    return 0;
}