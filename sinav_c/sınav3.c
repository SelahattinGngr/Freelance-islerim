#include <stdio.h>
#include <stdlib.h>

double *createArray(int *size)
{
    double *array = NULL;
    double num;
    *size = 0;

    do
    {
        printf("Enter a positive number (0 or negative number to stop): ");
        scanf("%lf", &num);

        if (num > 0)
        {
            (*size)++;
            array = (double *)realloc(array, (*size) * sizeof(double));
            array[(*size) - 1] = num;
        }
    } while (num > 0);

    return array;
}

void printArray(double *array, int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%lf ", array[i]);
    }
    printf("\n");
}

void freeArray(double *array)
{
    free(array);
}

int main()
{
    int size;
    double *array = createArray(&size);
    printArray(array, size);
    freeArray(array);

    return 0;
}
