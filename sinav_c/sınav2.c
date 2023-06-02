#include <stdio.h>
#include <stdlib.h>

int **createArr2d(int m, int n)
{
    int **tab = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        tab[i] = (int *)malloc(sizeof(int) * n);
    }

    return tab;
}

void fillArr(int **tab, int m, int n)
{
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("tab[%d][%d]: ", i, j);
            scanf("%d", &tab[i][j]);
        }
    }
}

void takeNprint(int **tab, int m, int n)
{
    int p, q;

    printf("Enter the inices (p and q): ");
    scanf("%d %d", &p, &q);

    if (p >= 0 && p < m && q >= 0 && q < n)
    {
        printf("Sub-array starting from tab[%d][%d]:\n", p, q);
        for (int i = p; i < m; i++)
        {
            for (int j = q; j < n; j++)
            {
                printf("%d ", tab[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Invalid indices!\n");
    }
}

void delArr(int **tab, int m)
{
    for (int i = 0; i < m; i++)
        free(tab[i]);

    free(tab);
}

int main()
{
    int m, n;
    int **arr;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    arr = createArr2d(m, n);
    fillArr(arr, m, n);
    takeNprint(arr, m, n);
    return 0;
}