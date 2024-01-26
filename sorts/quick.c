#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int *arr, int left, int right)
{
    int i, j, pivot;
    if (left < right)
    {
        i = left;
        j = right + 1;
        pivot = arr[left];
        do
        {
            do
            {
                i++;
            } while (arr[i] < pivot);
            do
            {
                j--;
            } while (arr[j] > pivot);
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
            }
        } while (i < j);
        swap(&arr[left], &arr[j]);
        quicksort(arr, left, j - 1);
        quicksort(arr, j + 1, right);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 9, 8, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}