#include <iostream>
using namespace std;

#define n 4
int placed[n];

int safe(int row, int col)
{
    // check only for current row and previous rows
    for (int i = 0; i < row; i++)
    {
        // same column OR diagonal attack
        if (placed[i] == col || abs(placed[i] - col) == abs(i - row))
        {
            return 0;
        }
    }

    return 1;
}

void solve(int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << placed[i] << " ";
        }
        cout << endl;

        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (safe(row, c))
        {
            placed[row] = c;
            solve(row + 1);
        }
    }
}

int main(){
    solve(0);

    return 0;
}
