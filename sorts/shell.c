#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void shellsort(int *arr, int n)
{
	int i, j, k, gap;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
			{
				swap(&arr[j], &arr[j + gap]);
			}
		}
	}
}

int main()
{
	int arr[] = {5, 4, 3, 2, 1, 6, 9, 8, 7, 10};
	int n = sizeof(arr) / sizeof(arr[0]);

	shellsort(arr, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}