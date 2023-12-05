#include <stdio.h>
#define MAX 1000000

int main(void)
{
	int numList[MAX] = {0};
	int primeList[MAX / 2] = {0};
	int n, primeCount = 0, superPrimeSum = 0;

	// 入力
	scanf("%d", &n);

	// 数字リストの作成
	for (int i = 0; i < n - 1; i++)
	{
		numList[i] = i + 2;
	}

	// エラトステネスの篩
	for (int i = 0; i < n - 1; i++)
	{
		// 0 は素数ではないのでスキップ
		if (numList[i] != 0)
		{
			// 0 でない先頭の数字は素数
			primeList[primeCount] = numList[i];
			primeCount++;

			// 素数の数が n / 2 を超えたら残りはすべて素数なので 0 を代入する必要なし
			if (primeCount > n / 2)
			{
				continue;
			}

			// 素数の倍数は素数でないためを 0 にする
			for (int j = i + numList[i]; j < n - 1; j += numList[i])
			{
				numList[j] = 0;
			}
		}
	}

	// スーパー素数の和を求める
	for (int i = 0; i < primeCount; i++)
	{
		// 0 が出てきたら終了
		if (primeList[primeList[i] - 1] == 0)
		{
			break;
		}

		// 素数番目の素数の和
		// インデックスが 0 から始まるため -1 する
		superPrimeSum += primeList[primeList[i] - 1];
	}

	printf("%d\n", superPrimeSum);
}