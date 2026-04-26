#include <iostream>
using namespace std;

#define INF 9999
#define V 3

void floyd(int graph[V][V])
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    cout << "Floyd Warshall: " << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int graph[V][V] = {
        {0, 5, INF},
        {INF, 0, 3},
        {2, INF, 0}};

    floyd(graph);

    return 0;
}