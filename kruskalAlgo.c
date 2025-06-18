#include <stdio.h>
#include <stdlib.h>
#include "disjointSet.h"

// comparator function to use in sorting
int comparator(const void *p1,const void *p2) {
    return ((int *)p1)[2] - ((int *)p2)[2];
}

void printMST(int n, int **edge) {
    for (int i = 0; i < n; i++)
    {
        printf("%d - %d -> %d", edge[i][0], edge[i][1], edge[i][2]);
        printf("\n");
    }
}

// Function to find the MST
int KruskalAlgo(int vertices, int edges, int edge[edges][3]) {
    int **mst = (int **)malloc((vertices-1) * sizeof(int *));
    for (int i = 0; i < vertices-1; i++)
    {
        mst[i] = (int *)malloc(3 * (sizeof(int)));
    }
    
    // First we sort the edge in Ascending order
    // so that we can access minimum distances/cost
    qsort(edge, edges, sizeof(edge[0]), comparator);

    // Create a Disjoint Set
    DisjointSet *ds = createDisjointSet(vertices+1);

    int minCost = 0;
    int count = 0;
    for (int i = 0; i < edges; i++)
    {
        int p1 = findParent(ds, edge[i][0]);
        int p2 = findParent(ds, edge[i][1]);
        int wt = edge[i][2];

        // If parent are different that means 
        // they are in different sets so union them
        if (p1 != p2)
        {
            mst[count][0] = edge[i][0];
            mst[count][1] = edge[i][1];
            mst[count][2] = edge[i][2];
            unionSet(ds, p1, p2);
            minCost += wt;
            count++;
        }
    }
    printMST(count, mst);
    return minCost;
} 

int main() {
    int edge[9][3] = {
        {1, 5, 4},
        {1, 4, 1},
        {4, 5, 9},
        {1, 2, 2},
        {2, 4, 3},
        {2, 3, 3},
        {3, 4, 5},
        {2, 6, 7},
        {3, 6, 8},
    };

    printf("%d", KruskalAlgo(6, 9, edge));

    return 0;
}