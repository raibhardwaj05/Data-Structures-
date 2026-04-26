#include <iostream>
using namespace std;

#define V 4
#define INF 9999

int minIndex(int dist[], int visited[])
{
    int u, min = INF;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            u = i;
        }
    }

    return u;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V], visited[V];

    // initialise dist and visited to INF and 0 resp.
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    // dist between src to itself is always 0
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        // get the min dist next node
        int u = minIndex(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            // if node is not visited and edge exists and the new dist < old dist then dist = new dist
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v]; // don't add in prims just dist[v] = graph[u][v]
            }
        }
    }

    cout << "Dijkstra:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << endl;
    }
}

void prims(int graph[V][V], int src)
{
    int dist[V], visited[V], parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;
    parent[src] = -1; // no parent for src node

    for (int i = 0; i < V - 1; i++)
    {
        int u = minIndex(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && graph[u][v] < dist[v])
            {
                dist[v] = graph[u][v];
                parent[v] = u; // setting parent node of the current node
            }
        }
    }

    cout << "Prims: " << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Parent: " << parent[i] << " -- " << i << " (" << dist[i] << ")" << endl;
    }
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6},
        {2, 0, 3, 8},
        {0, 3, 0, 0},
        {6, 8, 0, 0}};

    dijkstra(graph, 0);

    prims(graph, 0);

    return 0;
}