#include <stdio.h>
#define INF 999999999
void display(int n, int graph[n][n]);

void floydWarshallAlgo(int n,int graph[n][n]) {
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = graph[i][k] + graph[k][j];
                if (graph[i][j] > temp)
                {
                    graph[i][j] = temp;
                }
            }          
        }
    }
}

void display(int n, int graph[n][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
            {
                printf("x ");
                continue;
            }
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Enter No. of vertices and edges ");
    scanf("%d%d", &n, &m);
    // Adjacency Matrix
    printf("Adjacency Matrix\n");
    int adjMatrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adjMatrix[i][j] = 0;
                continue;
            }
            adjMatrix[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        printf("Enter edge (u v) and weight: ");
        scanf("%d%d%d", &u, &v, &w);
        adjMatrix[u][v] = w;
    }
    floydWarshallAlgo(n, adjMatrix);
    display(n, adjMatrix);
}