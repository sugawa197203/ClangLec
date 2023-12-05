# はじめに

ただのC言語のプログラム置き場です。参考文献にしないでください。

テキトーに書いたので、間違っているかもしれません。間違ってたらコッソーリ直します。

## Q1

M 個の整数の配列 Z と整数 N が与えられる。Z の中から M - N 個の整数を選んで、その和の最大値から最小値を引いた値 X を求めよ。

制約

```
1 <= M <= 10000
0 <= N < 10000
N < M
```

* 方針

    ソートした Z の大きい方から M - N 個を選ぶと最大値が求まる。小さい方から M - N 個を選ぶと最小値が求まる。最大値から最小値を引くと X が求まる。

    入力

    ```
    M
    N
    Z
    ```

    出力

    ```
    X
    ```

* 実装

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    // 比較関数
    int compare(const void *a, const void *b) {
        return *(int *)b - *(int *)a;
    }

    int main(void) {
        int m, n, i, maxsum = 0, minsum = 0, x = 0;
        int *z;

        // 入力
        scanf("%d", &m);
        scanf("%d", &n);

        // 配列の動的確保
        z = (int *)malloc(sizeof(int) * m);

        // 配列の入力
        for (i = 0; i < m; i++) {
            scanf("%d", &z[i]);
        }

        // ソート
        qsort(z, m, sizeof(int), compare);

        // 最大値計算
        for (i = 0; i < m - n; i++) {
            maxsum += z[i];
        }

        // 最小値計算
        for (i = m - 1; i >= n; i--) {
            minsum += z[i];
        }

        // X の計算
        x = maxsum - minsum;

        // 出力
        printf("%d\n", x);

        // 配列の解放
        free(z);

        return 0;
    }
    ```

* 実行

  * 例1

    入力

    ```
    3
    2
    1 2 3
    ```

    出力

    ```
    2
    ```

    一番和が小さい組み合わせは 1 で、一番和が大きい組み合わせは 3 である。最大値から最小値を引くと 2 となる。

  * 例3

    入力

    ```
    5
    3
    -2 -1 0 1 2
    ```

    出力

    ```
    6
    ```

    一番和が小さい組み合わせは -2, -1 で、一番和が大きい組み合わせは 1, 2 である。最大値から最小値を引くと 6 となる。

  * 例3

    入力

    ```
    5
    1
    1 -2 3 -4 5
    ```

    出力

    ```
    9
    ```

    一番和が小さい組み合わせは -4, -2, 1, 3 で、一番和が大きい組み合わせは -2, 1, 3, 5 である。最大値から最小値を引くと 9 となる。

## Q2

整数 N と N × N の行列 C が与えられる。C を右下がりで降順にソートした行列 D を出力せよ。

制約

```
1 <= N <= 100
```

* 方針

    行列を 45° 傾けて 2 次元配列に格納し、ソートするのが簡単？

    ```
    a b c
    d e f
    g h i
    ```

    ↓

    ```
    c
    b f
    a e i
    d h
    g
    ```

    入力

    ```
    N
    C_11 C_12 ... C_1N
    C_21 C_22 ... C_2N
    ...
    C_N1 C_N2 ... C_NN
    ```

    出力

    ```
    D_11 D_12 ... D_1N
    D_21 D_22 ... D_2N
    ...
    D_N1 D_N2 ... D_NN
    ```

* 実装

    ```c
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
    }
    ```

* 実行

  * 例1

    入力

    ```
    3
    10 1 3
    4 6 6
    7 8 6
    ```

    出力

    ```
    10 6 3 
    8 6 1 
    7 4 6
    ```

  * 例2

    入力

    ```
    5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    ```

    出力

    ```
    5 5 5 5 5
    4 4 4 4 4
    3 3 3 3 3
    2 2 2 2 2
    1 1 1 1 1
    ```

## Q3

以下の数列 F の第 M 項までのうち、下 5 桁が回文数となる項の個数 c を求めよ。

```
F(n) = F(n - 2) + F(n - 3)
F(0) = 3
F(1) = 0
F(2) = 2
```

制約

```
1 <= M <= 1000000
```

* 方針

    非連接3項漸化式の一般項求めたら楽なのかな、、、

    数弱なので、愚直に計算します。

    この問題、 5 桁未満の数字はゼロ埋めするか、 4 桁とか 3 桁の回文数として見るか、 5 桁以上が前提なのか書いてない不備があります。下記のコードでは 5 桁以上であることを前提としています。実際の想定は作問者に問い合わせてください。

    入力

    ```
    M
    ```

    出力

    ```
    c
    ```

* 実装

    ```c
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
    ```

* 実行

  * 例1

    入力

    ```
    10
    ```

    出力

    ```
    0
    ```

  * 例2

    入力

    ```
    100
    ```

    出力

    ```
    2
    ```

  * 例3

    入力

    ```
    202312
    ```

    出力

    ```
    1905
    ```

## Q4

入力 N に対して、 N 以下の素数番目の素数の和 S を求めよ。

制約

```
1 <= N <= 1000000
```

* 方針

  素数番目の素数はスーパー素数と言われています。

  エラトステネスの篩を使って素数を求め、素数番目の素数を求めます。

  入力

  ```
  N
  ```

  出力
   ```
  S
  ```

* 実装

    ```c
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

            superPrimeSum += primeList[primeList[i] - 1];
        }

        printf("%d\n", superPrimeSum);
    }
    ```

* 実行

  * 例1

    入力

    ```
    5
    ```

    出力

    ```
    8
    ```

  * 例2

    入力

    ```
    100
    ```

    出力

    ```
    317
    ```

  * 例3

    入力

    ```
    1000
    ```

    出力

    ```
    15489
    ```

  * 例4
  
    入力

    ```
    202312
    ```
        
    ```
    187109272
    ```
