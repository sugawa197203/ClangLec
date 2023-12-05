#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main(void)
{
	int n, i, j, l;
	int **matrix;
	int **matrixtmp;

	// 入力
	scanf("%d", &n);

	// 行列の確保
	matrix = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; i++)
	{
		matrix[i] = (int *)malloc(sizeof(int) * n);
	}

	// 行列の入力
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	// ソート用 2 次元配列の確保
	matrixtmp = (int **)malloc(sizeof(int *) * 2 * n - 1);
	for (i = 0; i < 2 * n - 1; i++)
	{
		if (i < n)
		{
			l = i + 1;
		}
		else
		{
			l = 2 * n - i - 1;
		}

		matrixtmp[i] = (int *)malloc(sizeof(int) * l);
	}

	// ソート用 2 次元配列の作成
	for (i = 0; i < 2 * n - 1; i++)
	{
		if (i < n)
		{
			for (j = 0; j <= i; j++)
			{
				matrixtmp[i][j] = matrix[j][n - i + j - 1];
			}
		}
		else
		{
			for (j = 0; j < 2 * n - i - 1; j++)
			{
				matrixtmp[i][j] = matrix[i - n + j + 1][j];
			}
		}
	}

	// ソート
	for (i = 0; i < 2 * n - 1; i++)
	{
		if (i < n)
		{
			l = i + 1;
		}
		else
		{
			l = 2 * n - i - 1;
		}

		qsort(matrixtmp[i], l, sizeof(int), compare);
	}

	// ソート用 2 次元配列の内容を元の行列に戻す
	for (i = 0; i < 2 * n - 1; i++)
	{
		if (i < n)
		{
			for (j = 0; j <= i; j++)
			{
				matrix[j][n - i + j - 1] = matrixtmp[i][j];
			}
		}
		else
		{
			for (j = 0; j < 2 * n - i - 1; j++)
			{
				matrix[i - n + j + 1][j] = matrixtmp[i][j];
			}
		}
	}

	// 出力
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}

		printf("\n");
	}

	return 0;
}