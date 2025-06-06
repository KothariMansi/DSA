#include <stdio.h>

void towerOfHanoi(int n, char src, char dest, char helper) {
    if (n==1)
    {
        printf("Transfer disk 1 from %c to %c\n",src, dest);
        return;
    }
    
    towerOfHanoi(n-1, src, helper, dest);
    printf("Transfer disk %d from %c to %c\n", n, src, dest);
    towerOfHanoi(n-1, helper, dest, src);
}

void main() {
    int n = 3;
    towerOfHanoi(3, 'S', 'D', 'H');
}