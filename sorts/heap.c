#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heapsort(int *arr, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
        for (k = n - i - 1; k > i; k--)
        {
            if (arr[k] < arr[k - 1])
            {
                swap(&arr[k], &arr[k - 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 9, 8, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}