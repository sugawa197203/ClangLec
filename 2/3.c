#include <stdio.h>

// 数字を逆順にする関数
int Reverse(int num)
{
    int a, b, c, d, e;
    a = num % 100000 / 10000;
    b = num % 10000 / 1000;
    c = num % 1000 / 100;
    d = num % 100 / 10;
    e = num % 10;

    return e * 10000 + d * 1000 + c * 100 + b * 10 + a;
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