# はじめに

ただのC言語のプログラム置き場です。参考文献にしないでください。

もしかしたら何かしらの問題に偶然似てるかもしれませんが、それは偶然です。

テキトーに書いたので、間違っているかもしれません。間違ってたらコッソーリ直します。

## 1

[アスキーコード表](https://www.tuatmcc.com/blog/2024-01-26-ascii-table/)

### 1-1

サンプル？なんのことでしょうか？

* コマンドライン引数

コマンドライン引数とは、プログラムを実行するときに Main 関数に引数を渡すことです。以下にコマンドライン引数で遊ぶだけのプログラムを示します。

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("%d : %s\n", i, argv[i]);
    }
}
```

コンパイルして実行してみましょう。

```bash
gcc arg.c
./a.out
```

こんなのが出てきます。

```bash
argc = 1
0 : ./a.out
```

argc は引数の数です。 argv は引数本体です。 argv には `./a.out` のみが入っているため、argc は 1 になります。次に、実行するときに色々付け加えて見ましょう。

```bash
./a.out hoge fuga
```

こんなのが出てきます。

```bash
argc = 3
0 : ./a.out
1 : hoge
2 : fuga
```

argc は 3 になりました。 argv には `./a.out` と `hoge` と `fuga` が入っています。

* `fprintf` と標準エラー出力

`fprintf` は指定されたファイルポインタに文字を出力する関数です。ファイルを開いて、そのファイルポインタを第1引数に入れ、第2引数にフォーマット、第3引数以降に変数を入れます。

以下に 1 から 10 を `out.txt` に書き出す例を示します。

```c
#include <stdio.h>

int main()
{
    FILE *fp;

    if ((fp = fopen("out.txt", "w")) == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    for (int i = 1; i <= 10; i++)
    {
        fprintf(fp, "%d\n", i);
    }
}
```

ここで、 `fprintf` の部分の第1引数を標準出力である `stdout` に変えてみましょう。余計な部分はコメントアウトしちゃってください。

```c
#include <stdio.h>

int main()
{
    // FILE *fp;

    // if ((fp = fopen("out.txt", "w")) == NULL)
    // {
    //  printf("Cannot open file.\n");
    //  return 1;
    // }

    for (int i = 1; i <= 10; i++)
    {
        fprintf(stdout, "%d\n", i);
    }
}
```

なんと画面に出力されました。

```bash
1
2
3
4
5
6
7
8
9
10
```

これは簡単に言うと、標準出力の `stdout` は画面に出力されるようになっているからです。 `open` 関数で取得したファイルポインタはファイルに出力されるようになっています。続いて、標準エラー出力である `stderr` に変えて実行してみましょう。

```c
#include <stdio.h>

int main()
{
    // FILE *fp;

    // if ((fp = fopen("out.txt", "w")) == NULL)
    // {
    //  printf("Cannot open file.\n");
    //  return 1;
    // }

    for (int i = 1; i <= 10; i++)
    {
        fprintf(stderr, "%d\n", i);
    }
}
```

なんと画面に出力されました。

```bash
1
2
3
4
5
6
7
8
9
10
```

これは標準エラー出力の `stderr` は画面に出力されるようになっているからです。標準出力と標準エラー出力って一緒のように見えますが、実際には違います。以下のコードを実行してみましょう。

```c
#include <stdio.h>

int main()
{
    fprintf(stdout, "This is stdout\n");
    fprintf(stderr, "This is stderr\n");
}
```

実行の再、リダイレクトを使いましょう。リダイレクトを使うと、標準出力と標準エラー出力を画面ではなく、ファイルに出力することができます。以下の 4 種類のコマンドを実行してみましょう。

* 普通に実行

```bash
./a.out
```

標準出力と標準エラー出力が混ざって出力されます。

```bash
This is stdout
This is stderr
```

* 標準出力を `out.txt` に出力

```bash
./a.out > out.txt
```

画面には標準エラー出力のみが出力されます。

```bash
This is stderr
```

* 標準エラー出力を `err.txt` に出力

```bash
./a.out 2> err.txt
```

画面には標準出力のみが出力されます。

```bash
This is stdout
```

* 標準出力を `out.txt` に出力し、標準エラー出力を `err.txt` に出力

```bash
./a.out > out.txt 2> err.txt
```

画面には何も出力されません。

なんとなくわかりましたか？ `printf` って `fprintf(stdout)` なんだぁって思うと思います。深掘りしすぎると終わらないので、標準出力あたりはここら辺でやめておきます。

* `if`, `while` の評価

`if` や `while` は条件式が `false` か `true` かで処理を分岐します。 `false` と `true` は `0` か `0じゃない` かで表されます。以下のコードを実行してみましょう。

```c
#include <stdio.h>

int main()
{
    if (100)
        printf("100 is true\n");

    if (1)
        printf("1 is true\n");

    if (0)
        printf("0 is true\n");

    if (-1)
        printf("-1 is true\n");

    if (0.0)
        printf("0.0 is true\n");

    if (0.1)
        printf("0.1 is true\n");
}
```

こんなのが出てきます。

```bash
100 is true
1 is true
-1 is true
0.1 is true
```

`0` のみ `false` になったのがわかると思います。これは `While` や `for` でもできます。

*  
