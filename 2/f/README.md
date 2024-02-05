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

1. 普通に実行

```bash
./a.out
```

標準出力と標準エラー出力が混ざって出力されます。

```bash
This is stdout
This is stderr
```

2. 標準出力を `out.txt` に出力

```bash
./a.out > out.txt
```

画面には標準エラー出力のみが出力されます。

```bash
This is stderr
```

3. 標準エラー出力を `err.txt` に出力

```bash
./a.out 2> err.txt
```

画面には標準出力のみが出力されます。

```bash
This is stdout
```

4. 標準出力を `out.txt` に出力し、標準エラー出力を `err.txt` に出力

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

* fscanf フォーマット

`fscanf` は指定されたファイルポインタから文字を読み込む関数です。ファイルを開いて、そのファイルポインタを第1引数に入れ、第2引数にフォーマット、第3引数以降に変数を入れます。

以下に文字列と数字を読み込むときのフォーマットを示します。

```c
char str[100];
int num;

fscanf(fp, "%s", str);
fscanf(fp, "%d", &num);
```

`%s` は文字列を読み込むフォーマットで、`%d` は数字を読み込むフォーマットです。

カンマで区切られた文字列を読み込む際は以下のようにします。入力として、`AAA,BBB,CCC` を想定します。

```c
char aaa[100];
char bbb[100];
char ccc[100];

fscanf(fp, "%[^,],%[^,],%s", aaa, bbb, ccc);
```

`%[^,]` は `,` を含まない任意の文字列を意味します。`^` が否定です。 `aaa` とか `AbCd` とか `$%&#` とかが該当します。なので、上記のフォーマットは、`[,を含まない任意文字列]` + `,` + `[,を含まない任意文字列]` + `,` + `[任意文字列]` という意味になります。最後が `%[^,]` だった場合、改行文字まで読み込んでしまうので、最後だけ `%s` にしています。

次に、数字と文字列が交互に並んでいる場合を考えます。入力として、`A111BB22CCC3` を想定します。以下に示すフォーマットでは読み込むことはできません。

```c
char aaa[100];
char bbb[100];
char ccc[100];
int a, b, c;

fscanf(fp, "%s%d%s%d%s%d", aaa, &a, bbb, &b, ccc, &c);
```

この場合、はじめの `%s` は `A` だけでなく `A111BB22CCC3` まで読み込んでしまいます。以下のフォーマットなら想定通りに読み込むことができます。

```c
char aaa[100];
char bbb[100];
char ccc[100];
int a, b, c;

fscanf(fp, "%[a-zA-Z]%d%[a-zA-Z]%d%[a-zA-Z]%d", aaa, &a, bbb, &b, ccc, &c);
```

`%[a-zA-Z]` は a ～ z までと、 A ～ Z までの文字列を読み込むフォーマットです。なので、上記のフォーマットは、`[アルファベットの文字列]` + `[数字]` + `[アルファベットの文字列]` + `[数字]` + `[アルファベットの文字列]` + `[数字]` という意味になります。

a ～ z の範囲の話を少し具体的に話すと ASCII コードの話になります。アスキーコード表は[こちら](https://www.tuatmcc.com/blog/2024-01-26-ascii-table/)を御覧ください。 `%[a-z]` の場合、 `a` のアスキーコードである `0x61` から `z` のアスキーコードである `0x7A` の範囲内にある文字を読み込むことができます。この範囲内にあるのはアルファベットの小文字しか無いため、 `%[a-z]` は小文字のアルファベットを受け付けるフォーマットであることがわかります。 `%[a-zA-Z]` の場合、上記に加え `A` のアスキーコードである `0x41` から `Z` のアスキーコードである `0x5A` の範囲内にある文字も読み込むことができます。つまり、 `%[a-zA-Z]` はアルファベットの大文字と小文字を受け付けるフォーマットであることがわかります。 `%[A-z]` の場合は、 `Z` (`0x5A`) と `a` (`0x61`) の間にある `[\]^_` も受け付けます。なので ``aB[\]^_`cD`` のような文字列も受け付けます。 `%[a-b]` というようなフォーマットは、`a`, `b` のみを受け付けます。

以下のようなフォーマットで、 ``!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~`` を入力すると、`str1` には ``!"#$%&'()*+,-./`` が、`str2` には `:;<=>?@` が、`str3` には ``[\]^_` `` が、`str4` には ``{|}~`` が入ります。

```c
char str1[100];
char str2[100];
char str3[100];
char str4[100];

fscanf(fp, "%[!-/]%[:-@]%[\[-`]%[{-~]", str1, str2, str3, str4);
```

次に読み込まない文字を指定する方法を考えます。例えば`@:abc     ` のような `abc` だけを読みたいけど前後にスペースや記号がある文字列を読み込むときです。以下のようなフォーマットを使います。

```c
char str[100];

fscanf(fp, "%*[^a-zA-Z]%[a-zA-Z]%*[^a-zA-Z]", str);
```

`%*[^a-zA-Z]` に `*` がついています。これは代入抑制です。読み込むけど第3引数以降の変数には代入しないことを意味します。上記では `%*[^a-zA-Z]` でアルファベットではない文字まで見るけど、 `str` には代入しないでね、そして `%[a-zA-Z]` でアルファベットを見て `str` に代入して、最後の `%*[^a-zA-Z]` でアルファベットではない文字まで見るけど、 `str` には代入しないでねという意味になります。 (`scanf` とかで試すときは、最後の `%*[^a-zA-Z]` は改行コードまで含むので、 `%*[^a-zA-Z\n]` とかにした方がいいかもしれません。)

英文 (アルファベット + スペース) が連続で並んでる場合は、 `%*[^a-zA-Z]%[a-zA-Z]` というパターンをループするのがいいかもしれません。

次に読み込む文字数をしていする方法を考えます。例えば、`abcdef` のような文字列で、はじめの 3 もじだけ読み込みたいときを想定します。以下のようなフォーマットを使います。

```c
char str[100];

fscanf(fp, "%3[a-zA-Z]", str);
```

`%3[a-zA-Z]` はアルファベットの文字列を 3 文字読み込むフォーマットです。 `%[a-zA-Z]` はアルファベットの文字列を読み込むフォーマットでした。 `%3[a-zA-Z]` は `%[a-zA-Z]` に 3 という数字をつけただけです。 このようにすると読み込む文字数を指定することができます。

* 文字列の長さと終わりの判定

文字列は `char` 型の配列で表されます。なので、 `char` の配列の長さは文字列の長さとは限りません。文字列の最後には必ず NULL 文字があります。以下に長さ 10 の `char` 配列に文字列 `abcd` を代入してある様子を示します。

![img](./10abcd.svg)

このことから、文字列の長さを求めたいときは、文字列の先頭から NULL 文字手前までの文字数を数えればいいことがわかります。また、文字列の終わりの判定は、先頭から読み込んだとき、 NULL 文字に当たったら終わりということになります。

* 大文字小文字の変換

文字は ASCII コードで表されます。アスキーコード表は[こちら](https://www.tuatmcc.com/blog/2024-01-26-ascii-table/)を御覧ください。大文字と小文字はアスキーコードで表すと、 `A` は `0x41` で `a` は `0x61` です。大文字と小文字の差は `0x20` です。なので、大文字を小文字に変換するには、 `0x20` を足し、小文字を大文字に変換するには、 `0x20` を引けばいいことがわかります。

(余談 : C 言語とかで**文字**を書くと、ASCIIコードの数字になるため、 `hoge < 'a'` のように比較演算子が使えます。また、 `'A' - 'a'` と書くと、 `0x41 - 0x61` となり、 `0x20` になるため、大文字と小文字の差を求めることができます。)

### 1-2

1-1 で長々と書いてすみません、、、

ここでは辞書を作るそうです。そして単語順で出力する。~~ハッシュテーブルがよさそう~~ 簡単に線形リストで実装します。

```c
#include <stdio.h>
#include <string.h>

#define MAXLENGTH 20
#define DICTSIZE 50

char dictionary[DICTSIZE][MAXLENGTH + 1];
int dictcount[DICTSIZE];

int findWord(char *word)
{
	for (int i = 0; i < DICTSIZE; i++)
	{
		// 文字が一致した！
		if (strcmp(dictionary[i], word) == 0)
		{
			return i;
		}
		// 文字が一致しなかったら、空いてるかチェックし、空いてたらそこに入れる
		else if (strcmp(dictionary[i], "") == 0)
		{
			strcpy(dictionary[i], word);
			return i;
		}
	}
	return -1;
}

void setDict(char *word)
{
	int index = findWord(word);
	if (index == -1)
	{
		// 辞書が満杯
		fprintf(stderr, "Error: dictionary overflow\n");
		return;
	}
	dictcount[index]++;
}

void printfDictOrder()
{
	// 辞書をバブルソートする
	// いっしょにdictcountもソートする
	for (int i = 0; i < DICTSIZE; i++)
	{
		for (int j = 0; j < DICTSIZE - i - 1; j++)
		{
			// 空の辞書はソートしない
			if (strcmp(dictionary[j + 1], "") == 0)
			{
				break;
			}

			if (strcmp(dictionary[j], dictionary[j + 1]) > 0)
			{
				// 辞書を入れ替える
				char tmp[MAXLENGTH + 1];
				strcpy(tmp, dictionary[j]);
				strcpy(dictionary[j], dictionary[j + 1]);
				strcpy(dictionary[j + 1], tmp);

				// dictcountも入れ替える
				int tmp2 = dictcount[j];
				dictcount[j] = dictcount[j + 1];
				dictcount[j + 1] = tmp2;
			}
		}
	}

	// 辞書を出力する
	for (int i = 0; i < DICTSIZE; i++)
	{
		// 空の辞書は出力しない
		if (strcmp(dictionary[i], "") == 0)
		{
			break;
		}
		printf("%s : %d\n", dictionary[i], dictcount[i]);
	}
}

int main()
{
	char buf[MAXLENGTH];
	while (scanf("%s", buf) != EOF)
	{
		setDict(buf);
	}

	printfDictOrder();
}

```

`dictionary` は単語の辞書、 `dictcount` は同じインデックス番号の `dictionary` の単語の出現回数を表します。 `findWord` 関数は単語を辞書に入れる関数です。 `setDict` 関数は単語を辞書に入れる関数です。 `printfDictOrder` 関数は辞書を出力する関数です。`setDict` 関数で辞書に追加するとき、はじめに `findWord` 関数で辞書に存在するか線形探索でチェックします。文字列の比較、コピーは `string.h` にある `strcmp`, `strcpy` を使います。 `findWord` 関数で辞書に存在すれば、そのインデックス番号を返します。線形探索で、辞書から空文字列が出てきたら、探索し終わっているので存在しなかったことを意味します。その空文字列のインデックスは空いてるので、新しく単語を入れ、そのインデックス番号を返します。`setDict` 関数で、単語のインデックス番号を取得したら、そのインデックスに対応する `dictcount` をインクリメントします。辞書に単語を追加し終わったら、`printfDictOrder` 関数では、辞書をソートと表示をします。ソートするときに、 `dictcount` も一緒にソートします。ソートはバブルソートで実装しています。辞書の文字列をスワップする際、該当する`dictcount` もソートして下さい。ソートしたら、辞書を単語の出現回数とともに出力します。出力するとき、辞書の空文字列が出てきたら、辞書の終わりなので、出力を終了します。

リダイレクトで以下のファイルを入力にして実行します。

```
banana
apple
melon
grape
apple
melon
apple
```

出力は以下のようになります。

```
apple : 3
banana : 1
grape : 1
melon : 2
```

挿入後の `dictionary` と `dictcount` の様子は以下のようになります。 

![img](./dictunsort.svg)

ソート後の `dictionary` と `dictcount` の様子は以下のようになります。

![img](./sorted.svg)

### 1-3

1-2 の頻度順らしいです。バブルソートは[安定ソート](https://ja.wikipedia.org/wiki/%E5%AE%89%E5%AE%9A%E3%82%BD%E3%83%BC%E3%83%88)なので、辞書順でソートしてから頻度順でソートすると、同じ頻度内では辞書順になります。なので、 1-2 のプログラムで、辞書順にソートする部分のあとに、頻度順にソートする部分を追加するだけで十分です。(~~手抜きだー！~~)

```c
#include <stdio.h>
#include <string.h>

#define MAXLENGTH 20
#define DICTSIZE 50

char dictionary[DICTSIZE][MAXLENGTH + 1];
int dictcount[DICTSIZE];

int findWord(char *word)
{
	for (int i = 0; i < DICTSIZE; i++)
	{
		// 文字が一致した！
		if (strcmp(dictionary[i], word) == 0)
		{
			return i;
		}
		// 文字が一致しなかったら、空いてるかチェックし、空いてたらそこに入れる
		else if (strcmp(dictionary[i], "") == 0)
		{
			strcpy(dictionary[i], word);
			return i;
		}
	}
	return -1;
}

void setDict(char *word)
{
	int index = findWord(word);
	if (index == -1)
	{
		// 辞書が満杯
		fprintf(stderr, "Error: dictionary overflow\n");
		return;
	}
	dictcount[index]++;
}

void printfDictOrder()
{
	// 辞書をバブルソートする
	// いっしょにdictcountもソートする
	for (int i = 0; i < DICTSIZE; i++)
	{
		for (int j = 0; j < DICTSIZE - i - 1; j++)
		{
			// 空の辞書はソートしない
			if (strcmp(dictionary[j + 1], "") == 0)
			{
				break;
			}

			if (strcmp(dictionary[j], dictionary[j + 1]) > 0)
			{
				// 辞書を入れ替える
				char tmp[MAXLENGTH + 1];
				strcpy(tmp, dictionary[j]);
				strcpy(dictionary[j], dictionary[j + 1]);
				strcpy(dictionary[j + 1], tmp);

				// dictcountも入れ替える
				int tmp2 = dictcount[j];
				dictcount[j] = dictcount[j + 1];
				dictcount[j + 1] = tmp2;
			}
		}
	}

	// dictcount をバブルソートする
	// いっしょにdictionaryもソートする
	for (int i = 0; i < DICTSIZE; i++)
	{
		for (int j = 0; j < DICTSIZE - i - 1; j++)
		{
			// 空の辞書はソートしない
			if (strcmp(dictionary[j + 1], "") == 0)
			{
				break;
			}

			if (dictcount[j] < dictcount[j + 1])
			{
				// dictcountを入れ替える
				int tmp = dictcount[j];
				dictcount[j] = dictcount[j + 1];
				dictcount[j + 1] = tmp;

				// dictionaryも入れ替える
				char tmp2[MAXLENGTH + 1];
				strcpy(tmp2, dictionary[j]);
				strcpy(dictionary[j], dictionary[j + 1]);
				strcpy(dictionary[j + 1], tmp2);
			}
		}
	}

	// 辞書を出力する
	for (int i = 0; i < DICTSIZE; i++)
	{
		// 空の辞書は出力しない
		if (strcmp(dictionary[i], "") == 0)
		{
			break;
		}
		printf("%s : %d\n", dictionary[i], dictcount[i]);
	}
}

int main()
{
	char buf[MAXLENGTH];
	while (scanf("%s", buf) != EOF)
	{
		setDict(buf);
	}

	printfDictOrder();
}


```

リダイレクトで以下のファイルを入力にして実行します。

```
banana
apple
orange
grape
melon
apple
melon
apple
banana
banana
```

出力は以下のようになります。

```
apple : 3
banana : 3
melon : 2
grape : 1
orange : 1
```

挿入後の `dictionary` と `dictcount` の様子は以下のようになります。 

![img](./dict2.svg)

辞書順ソート後の `dictionary` と `dictcount` の様子は以下のようになります。

![img](./dict3.svg)

頻度順ソート後の `dictionary` と `dictcount` の様子は以下のようになります。

![img](./dict4.svg)
