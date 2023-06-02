#include <stdio.h>
#include <stdlib.h>

int *createArr(int size)
{
    int *number = (int *)malloc(sizeof(int) * size);

    return number;
}

void fillArr(int *number, int size)
{
    int tmp = 1;
    for (int i = 0; i < size; i++, tmp++)
    {
        number[i] = tmp;
    }
}

void printArr(int *number, int size)
{
    while (--size >= 0)
    {
        printf("%d ", number[size]);
    }
}

void delArr(int *number)
{
    free(number);
}

int main()
{
    int *number;
    int m;

    printf("Please insert the 'm' value : ");
    scanf("%d", &m);

    number = createArr(m);
    fillArr(number, m);
    printArr(number, m);
    delArr(number);
}