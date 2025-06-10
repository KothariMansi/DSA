#include <stdio.h>
#define MAX 50

int main() {
    // char name[20];
    // printf("Enter name ");
    // scanf("%s", &name);
    // printf("\nYour name is %s.\n", name);

    char buff[MAX];
    printf("Enter a string.\n");
    fgets(buff, MAX, stdin);
    printf("The string is %s\n", buff);

    char str1[10] = "C";
    char str2[10] = "Language";
    puts(str1);
    puts(str2);

    return 0;
}