#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
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

	qsort(z, m, sizeof(int), compare);

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