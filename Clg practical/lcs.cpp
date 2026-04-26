#include <iostream>
#include <string.h>
using namespace std;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

void lcs(char A[], char B[])
{
    int n = strlen(A);
    int m = strlen(B);

    // +1 because we need an extra 0 row and 0 col in lcs
    int path[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                path[i][j] = 0;
            }
            else if (A[i - 1] == B[j - 1])
            {
                path[i][j] = 1 + path[i - 1][j - 1];
            }
            else
            {
                path[i][j] = max(path[i][j - 1], path[i - 1][j]);
            }
        }
    }

    cout << "LCS: " << path[n][m];
}

int main()
{
    lcs((char *)"ABC", (char *)"AC");

    return 0;
}