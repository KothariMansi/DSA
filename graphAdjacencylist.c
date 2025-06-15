#include <stdio.h>
#include <stdlib.h>

/*
    vertices - 1, 2, 3
    1 -> 2 -> 3
    2 -> 1 -> 3
    3 -> 1 -> 2
*/

// Define the structure for the adjacency list node
struct AdjListNode
{
    int dest; // data or value
    struct AdjListNode *next;
};

// Define the structure for an adjacency list
struct AdjList
{
    struct AdjListNode* head; // 1 vertice -> list -> head // 2 vertice -> list -> head....
};

// Define the structure for a graph
struct Graph
{
    int V; // number of vertices
    struct AdjList *array; // 1, 2, 3
};

// Function to create a new Adjacenct List Node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode =  (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create Graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph; 
}

// Add Edge in Graph
void addEdge(struct Graph *graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add and edge from dest to src
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform BFS traversal
// Use Queue data structure to perofmr BFS
// Create a visited array
// Go to a node and ask who are you neighbour
void BFS(struct Graph *graph, int startVertex) {
    // Create a Visited array
    int *visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
    {
        visited[i] = 0;
    }

    int *queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0; // remove from front
    int rear = 0; // add from rear
    visited[startVertex] = 1; // Make the vertex to visited in visited array
    queue[rear++] = startVertex; // Add the starting vertex to queue

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        struct AdjListNode *temp = graph->array[currentVertex].head;
        while (temp)
        {
            int adjVertex = temp->dest;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    free(queue);
    free(visited);
}

// A utility function use by DFS
void DFSUtil(int v, int* visited,struct Graph *graph) {
    visited[v] = 1;
    printf("%d ", v);
    struct AdjListNode* node = graph->array[v].head;
    while (node)
    {
        int adjVertex = node->dest;
        if (!visited[adjVertex])
        {
            DFSUtil(adjVertex, visited, graph);
        } 
        node = node->next;  
    } 
}

// Function to perform DFS traversal
void DFS(struct Graph *graph, int startVertex) {
    int *visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
    {
        visited[i] = 0;
    }
    DFSUtil(startVertex, visited, graph);
    free(visited);   
}

int main() {
    int V = 7;
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    BFS(graph, 1);
    printf("\n");
    DFS(graph, 0);
    printf("\nDone ");
}