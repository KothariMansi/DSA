#include <stdio.h>

int main() {
    int arr[5];
    printf("Enter Array Elements\n");
    for(int i = 0; i < 5; i++) {
        printf("Enter Number ");
        scanf("%d", &arr[i]);
        printf("\n");
    }
    // Traversing Array and Displaying them
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    int a = 0, b = 0;
    int arr2[4][3] = {{1,2,3}, {3,2,1}, {3,5,6}, {7,8,6}};
    // traversing 2D array
    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < 3; b++)
        {
            printf("arr[%d][%d] = %d \n", a, b, arr2[a][b]);
        }
    }

    int x = 0, y = 0, z = 0;
    int arr3[4][3][2] = {
        {{1, 0},{2, 0},{3, 0}},
        {{3, 0},{2, 0},{1, 0}}, 
        {{3, 0},{5, 0},{6, 0}}, 
        {{7, 0},{8, 0},{6, 0}}
    };
    // traversing 3D array
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 3; y++)
        {
            for (z = 0; z < 2; z++)
            {
                printf("arr[%d][%d][%d] = %d \n", x, y, z, arr3[x][y][z]);
            }
        }
    }

    return 0;
}