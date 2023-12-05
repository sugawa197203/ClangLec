#include <stdio.h>

// 数字を逆順にする関数
int Reverse(int num)
{
	int result = 0;
	while (num != 0)
	{
		result *= 10;
		result += num % 10;
		num /= 10;
	}
	return result;
}

int main()
{
	int m;
	int f0 = 3, f1 = 0, f2 = 2, f3 = f1 + f0;
	int count = 0;

	// 入力
	scanf("%d", &m);

	for (int i = 3; i <= m; i++)
	{
		f0 = f1;
		f1 = f2;
		f2 = f3;
		f3 = f1 + f0;

		// 5 桁以上の場合は下 5 桁だけを取り出す
		f3 %= 100000;

		// 回文数かどうか判定
		if (f3 >= 10000 && f3 == Reverse(f3))
		{
			count++;
		}
	}

	// 出力
	printf("%d\n", count);
	return 0;
}