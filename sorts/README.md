# C 言語ソートプログラム

## バブルソート

```c
#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblesort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubblesort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

## 選択ソート

```c
#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionsort(int *arr, int n)
{
    int i, j, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 9, 8, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

## 挿入ソート

```c
#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionsort(int *arr, int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 9, 8, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

## クイックソート

```c
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
```

## マージソート

```c
#include <stdio.h>

void margesort(int *arr, int l, int r)
{
    if (l == r)
    {
        return;
    }

    int m = (l + r) / 2;

    margesort(arr, l, m);
    margesort(arr, m + 1, r);

    int i = l;
    int j = m + 1;
    int k = 0;

    for (k = l; k <= r; k++)
    {
        if (i == m + 1)
        {
            break;
        }
        else if (j == r + 1)
        {
            break;
        }
        else if (arr[i] < arr[j])
        {
            i++;
        }
        else
        {
            int tmp = arr[j];
            for (int k = j - 1; k >= i; k--)
            {
                arr[k + 1] = arr[k];
            }
            arr[i] = tmp;
            i++;
            j++;
            m++;
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 9, 8, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    margesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

## ヒープソート

```c
#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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
```

## シェイカーソート

```c
#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shakersort(int *arr, int n)
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

    shakersort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

## シェルソート
