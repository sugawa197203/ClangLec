# はじめに

ただのC言語のプログラム置き場です。参考文献にしないでください。

テキトーに書いたので、間違っているかもしれません。間違ってたらコッソーリ直します。

Q3 の自信がありません。合ってたら合ってるよ～って教えてください。

Q2 は特にテキトーです。

## Q1

M 個の整数の配列 Z と整数 N が与えられる。Z の中から M - N 個の整数を選んで、その和の最大値から最小値を引いた値 X を求めよ。

制約

```txt
1 <= M <= 10000
0 <= N < 10000
N < M
```

* 方針

    ソートした Z の大きい方から M - N 個を選ぶと最大値が求まる。小さい方から M - N 個を選ぶと最小値が求まる。最大値から最小値を引くと X が求まる。

    入力

    ```txt
    M
    N
    Z
    ```

    出力

    ```txt
    X
    ```

* 実装

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int swap(int *a, int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    int bubbleSort(int *array, int size)
    {
        int i, j;

        for (i = 0; i < size - 1; i++)
        {
            for (j = size - 1; j > i; j--)
            {
                if (array[j] > array[j - 1])
                {
                    swap(&array[j], &array[j - 1]);
                }
            }
        }
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

        bubbleSort(z, m);

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
    ```

* 実行

  * 例1

    入力

    ```txt
    3
    2
    1 2 3
    ```

    出力

    ```txt
    2
    ```

    一番和が小さい組み合わせは 1 で、一番和が大きい組み合わせは 3 である。最大値から最小値を引くと 2 となる。

  * 例3

    入力

    ```txt
    5
    3
    -2 -1 0 1 2
    ```

    出力

    ```txt
    6
    ```

    一番和が小さい組み合わせは -2, -1 で、一番和が大きい組み合わせは 1, 2 である。最大値から最小値を引くと 6 となる。

  * 例3

    入力

    ```txt
    5
    1
    1 -2 3 -4 5
    ```

    出力

    ```txt
    9
    ```

    一番和が小さい組み合わせは -4, -2, 1, 3 で、一番和が大きい組み合わせは -2, 1, 3, 5 である。最大値から最小値を引くと 9 となる。

## Q2

整数 N と N × N の行列 C が与えられる。C を右下がりで降順にソートした行列 D を出力せよ。

制約

```txt
1 <= N <= 100
-10^6 <= C_ij <= 10^6
```

* 方針

    行列を 45° 傾けて 2 次元配列に格納し、ソートするのが簡単？

    ```txt
    a b c
    d e f
    g h i
    ```

    ↓

    ```txt
    c
    b f
    a e i
    d h
    g
    ```

    ↓

    ```txt
    a b c
    d e f
    g h i
    ```

    入力

    ```txt
    N
    C_11 C_12 ... C_1N
    C_21 C_22 ... C_2N
    ...
    C_N1 C_N2 ... C_NN
    ```

    出力

    ```txt
    D_11 D_12 ... D_1N
    D_21 D_22 ... D_2N
    ...
    D_N1 D_N2 ... D_NN
    ```

* 実装

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    void swap(int *a, int*b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    void bubbleSort(int *array, int size)
    {
        int i, j;

        for (i = 0; i < size - 1; i++)
        {
            for (j = size - 1; j > i; j--)
            {
                if (array[j] > array[j - 1])
                {
                    swap(&array[j], &array[j - 1]);
                }
            }
        }
    }

    int main(void)
    {
        int n, i, j, l;
        int **matrix;
        int**matrixtmp;

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

            bubbleSort(matrixtmp[i], l);
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
    ```

* 実行

  * 例1

    入力

    ```txt
    3
    10 1 3
    4 6 6
    7 8 6
    ```

    出力

    ```txt
    10 6 3 
    8 6 1 
    7 4 6
    ```

  * 例2

    入力

    ```txt
    5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    ```

    出力

    ```txt
    5 5 5 5 5
    4 4 4 4 4
    3 3 3 3 3
    2 2 2 2 2
    1 1 1 1 1
    ```

## Q3

以下の数列 F の第 M 項までのうち、下 5 桁が回文数となる項の個数 c を求めよ。

```txt
F(n) = F(n - 2) + F(n - 3)
F(0) = 3
F(1) = 0
F(2) = 2
```

制約

```txt
1 <= M <= 1000000
```

* 方針

    非連接3項漸化式の一般項求めたら楽なのかな、、、

    数弱なので、愚直に計算します。

    `100` とか `1210` は `00100` とか `01210` って見ないでそもそも 5 桁未満は考えないらしい。

    **見た感じ `100` とか `1210` みたいな数字は 5 桁未満になかった(たぶん)。**

    入力

    ```txt
    M
    ```

    出力

    ```txt
    c
    ```

* 実装

    ```c
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

        for (int i = 4; i <= m; i++)
        {
            f0 = f1;
            f1 = f2;
            f2 = f3;
            f3 = f1 + f0;

            // 5 桁以上の場合は下 5 桁だけを取り出す
            f3 %= 100000;

            // 回文数かどうか判定
            if (f3 == Reverse(f3))
            {
                count++;
            }
        }

        // 出力
        printf("%d\n", count);
        return 0;
    }
    ```

    5 桁未満を飛ばしたければ `f0`, `f1`, `f2` の初期化をその項まで飛ばして `for` 文の開始を変えればいいと思います。

    ```c
    int f0 = 3480, f1 = 4610, f2 = 6107, f3 = f1 + f0;
    ```

    ```c
    for (int i = 33; i <= m; i++)
    ```

* 実行

  * 例1

    入力

    ```txt
    10
    ```

    出力

    ```txt
    0
    ```

  * 例2

    入力

    ```txt
    100
    ```

    出力

    ```txt
    2
    ```

  * 例3

    入力

    ```txt
    202312
    ```

    出力

    ```txt
    2094
    ```

## Q4

入力 N に対して、 N 以下の素数番目の素数の和 S を求めよ。

制約

```txt
1 <= N <= 1000000
```

* 方針

  素数番目の素数はスーパー素数と言われています。

  [エラトステネスの篩](https://manabitimes.jp/math/992)を使って素数を求め、素数番目の素数を求めます。

  入力

  ```txt
  N
  ```

  出力

   ```txt
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

        return 0;
    }
    ```

* 実行

  * 例1

    入力

    ```txt
    5
    ```

    出力

    ```txt
    8
    ```

  * 例2

    入力

    ```txt
    100
    ```

    出力

    ```txt
    317
    ```

  * 例3

    入力

    ```txt
    1000
    ```

    出力

    ```txt
    15489
    ```

  * 例4
  
    入力

    ```txt
    202312
    ```

    ```txt
    187109272
    ```

## その他

* `malloc` で動的確保した配列は `free` しなかったらどうなる？

  授業で扱う程度のすぐ終わるプログラムでは基本的に `free` し忘れてもプログラムの実行が終了するときに自動的に解放されるので問題ないです。ただし、メモリをたくさん使いたいプログラムを書くときは `free` し忘れるとメモリが足りなくなってプログラムが落ちるので注意してください。また、 24 時間 356 日稼働するようなプログラムを書くときは `free` し忘れるとメモリが足りなくなってプログラムが落ちるので注意してください。

* `break` と `continue` って何？

    `break` はループを終了するときに使います。 `continue` は次のループに行くときに使います。

    ```c
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            break;
        }
        printf("%d\n", i);
    }
    ```

    上記のプログラムは 0 から 4 までの数字を出力します。 `i` が 5 のときに `break` が実行されてループが抜けるからです。

    出力

    ```txt
    0
    1
    2
    3
    4
    ```

    ```c
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            continue;
        }
        printf("%d\n", i);
    }
    ```

    上記のプログラムは 5 以外の 0 から 9 までの数字を出力します。 `i` が 5 のときに `continue` が実行されて次のループに行くからです。

    出力

    ```txt
    0
    1
    2
    3
    4
    6
    7
    8
    9
    ```

* リダイレクトでデバッグを簡単にしよう

    リダイレクトをすると入力処理が簡単になります。試しに Q2 でやってみましょう。

    `q1input1.txt` というテキストファイルを作成して以下の内容を書き込んでください。

    ```txt
    3
    10 1 3
    4 6 6
    7 8 6
    ```

    プログラムは普通にコンパイルします。

    ```bash
    gcc q2.c
    ```

    実行するときに `<` を使ってリダイレクトします。

    ```bash
    ./a.out < q2input1.txt
    ```

    すると、 `q2input1.txt` の内容が入力された状態でプログラムが実行されます。

    ```txt
    10 6 3 
    8 6 1 
    7 4 6
    ```

    実行のたびに入力する手間が省けて便利です。入力するテキストファイルを変えるときは `q2input1.txt` の部分を変えてください。
