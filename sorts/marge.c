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