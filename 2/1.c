#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int bubbleSort(int *array, int size)
{
    int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = size - 1; j > i; j--)
        {
            if (array[j] > array[j - 1])
            {
                swap(&array[j], &array[j - 1]);
            }
        }
    }
}

int main(void)
{
    int m, n, i, maxsum = 0, minsum = 0, x = 0;
    int *z;

    scanf("%d", &m);
    scanf("%d", &n);

    z = (int *)malloc(sizeof(int) * m);

    for (i = 0; i < m; i++)
    {
        scanf("%d", &z[i]);
    }

    bubbleSort(z, m);

    for (i = 0; i < m - n; i++)
    {
        maxsum += z[i];
    }

    for (i = m - 1; i >= n; i--)
    {
        minsum += z[i];
    }

    x = maxsum - minsum;

    printf("%d\n", x);

    free(z);

    return 0;
}