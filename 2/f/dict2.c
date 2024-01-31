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
