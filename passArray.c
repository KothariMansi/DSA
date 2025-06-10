#include <stdio.h>

float calculateSum(float age[]) {
    float sum = 0.0;
    int i;
    for (i = 0; i < 4; i++)
    {
        sum += age[i];
    }
    return sum;
}

void displayNumbers(int num[2][2]) {
    int i, j;
    printf("Numbers you have entered.\n");
    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2; j++)
        {
            printf("%d\t", num[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float result, age[] = {2, 2 , 3, 5};
    result = calculateSum(age);
    printf("Sum : %.2f", result);

    int num[2][2] = {1, 2, 3, 4};
    displayNumbers(num);

    return 0;
}