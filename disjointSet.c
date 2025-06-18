#include <stdio.h>
#include <stdlib.h>

// structure to represent the disjoint set
typedef struct DisjointSet
{
    int *parent; // Array to store the parent of each element
    int *rank;  // Array to store the rank of each element
    int n;      // Number of elements
} DisjointSet;


// Function to create a new Disjoint Set with n elements
DisjointSet* createDisjointSet(int n) {
    DisjointSet *ds = (DisjointSet *)malloc(sizeof(DisjointSet));
    if (ds == NULL)
    {
        printf("Overflow\n");
        exit(EXIT_FAILURE);
    }

    ds->parent = (int*)malloc(n * sizeof(int));
    ds->rank = (int*)malloc(n * sizeof(int));
    if (ds->parent == NULL || ds->rank == NULL)
    {
        printf("Overflow\n");
        free(ds);
        exit(EXIT_FAILURE);
    }

    ds->n = n;

    for (int i = 1; i <= n; i++)
    {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
    return ds;
}

// Function to find the representative(parent) of set that contains element i
int findParent(DisjointSet *ds, int i) {
    // Path compression: Update parent pointer along the way
    if (ds->parent[i] != i)
    {
        ds->parent[i] =  findParent(ds, ds->parent[i]);
    }
    return ds->parent[i];
}

// Function to perform union of two sets
void unionSet(DisjointSet *ds, int u, int v) {
    int pu = findParent(ds, u);
    int pv = findParent(ds, v);

    // if parent are same than elements are already in the same set
    if (pu == pv)
    {
        return;
    }

    // Union by rank: Attach the smaller rank tree to the larger rank tree
    int ru = ds->rank[pu];
    int rv = ds->rank[pv];

    if (ru < rv)
    {
        ds->parent[pu] = pv;
    } else if (rv < ru)
    {
        ds->parent[pv] = pu;
    } else {
        // If rank are the same make onw root the parent of other and increment its rank
        ds->parent[pv] = pu;
        ds->rank[pu]++;
    }
}


int main() {
    int n = 7;
    DisjointSet *ds = createDisjointSet(n+1);
    unionSet(ds, 1, 2);
    unionSet(ds, 2, 3);
    unionSet(ds, 4, 5);
    unionSet(ds, 6, 7);
    int p1 = findParent(ds, 1);
    int p7 = findParent(ds, 7);
    printf("%d and  %d belong to same set? = %s", 1, 7, p1 == p7 ? "Yes": "No");
    printf("\n");
    unionSet(ds, 5, 6);
    unionSet(ds, 3, 7);
    p1 = findParent(ds, 1);
    p7 = findParent(ds, 7);
    printf("%d and  %d belong to same set? = %s", 1, 7, p1 == p7 ? "Yes": "No");

    return 0;
}