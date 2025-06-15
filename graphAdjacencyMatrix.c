#include <stdio.h>

int main() {
    int n, m;
    printf("Enter No. of vertices and edges ");
    scanf("%d%d", &n, &m);
    // Adjacency Matrix
    printf("Adjacency Matrix");
    int adjMatrix[n+1][n+1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}