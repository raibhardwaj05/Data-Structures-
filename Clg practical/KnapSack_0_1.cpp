#include <iostream>
using namespace std;

void knapsack(int table[5][9], int val[], int wt[], int max_wt, int items)
{
    for (int i = 1; i <= items; i++)
    {
        for (int w = 1; w <= max_wt; w++)
        {
            if (wt[i - 1] <= w)
            {
                table[i][w] = max(val[i - 1] + table[i - 1][w - wt[i - 1]], table[i - 1][w - wt[i - 1]]);
            }
            else
            {
                table[i][w] = table[i - 1][w - wt[i - 1]];
            }
        }
    }
    cout<<"Max Profit: "<<table[items][max_wt];
}

int main()
{
    int val[] = {2, 3, 1, 4};
    int wt[] = {3, 4, 6, 5};
    int max_wt = 8, items = 4;

    int table[5][9] = {0};

    knapsack(table, val, wt, max_wt, items);

    return 0;
}