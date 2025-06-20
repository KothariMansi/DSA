#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define V 5

/* 
    A utility function to find the vertex with minimum key value
    from the set of vertices not yet included in MST
*/
int minKey(int key[], bool mstSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

/*
    A utility function to print the constructed MST stored in parent
*/
int printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\t\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
    }
}

/*
    Function to construct and print MST for 
    a graph represented using adjacency matrix
*/
void primMSt(int graph[V][V]) {
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key value used to pick minimum edge weight in cut
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX, mstSet[i] = false;
    }
    // Always include 1st vertex in MST
    // Make key = 0, so that this vertex is picked as first vertex.
    key[0] = 0;

    // First node is always root of MST
    parent[0] = -1;
    for (int count = 0; count < V; count++)
    {
        /*
            Pick the minimum key vertex
            from the set for vertices
            not include in MSTSet
        */
       int u = minKey(key, mstSet);
       // Add the picked vertex to MST Set
       mstSet[u] = true;

       /*
           Update key's value and parent's index of
           adjacent vertices of the picked vertex.
           Consider only those which are not yet 
           included in MST Set
       */
        for (int v = 0; v < V; v++)
        {
            /* 
                graph[u][v] is non zero
                only for adjacent vertices of
                m MSTSet[v] == false for vertices
                not yet include in MST
                Update the key only if 
                graph[u][v] is smaller than key[v]
            */
           if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v])
           {
                parent[v] = u;
                key[v] = graph[u][v];
           }
        }
    }
    printMST(parent, graph);
}

int main() {
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMSt(graph);

    return 0;
}