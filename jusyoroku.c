#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

typedef struct Data Data;

struct Data
{
	char lastName[SIZE];
	char firstName[SIZE];
	char address[SIZE];
	char postNumber[SIZE];
	int birthYear;
	int birthMonth;
	int birthDay;
	char phoneNumber[SIZE];
	Data *next;
};

Data *newNode()
{
	Data *data = (Data *)malloc(sizeof(Data));
	data->next = NULL;
	return data;
}

int readData(Data *root)
{
	char fileName[SIZE];
	FILE *fp;

	printf("読み込むファイル名を入力してください: ");
	scanf("%s", fileName);

	if ((fp = fopen(fileName, "r")) == NULL)
	{
		puts("ファイルを開けませんでした");
		return -1;
	}

	Data *p = root;
	Data *pp;

	do
	{
		p->next = newNode();
		pp = p;
		p = p->next;
	} while (fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%d/%d/%d,%s\n",
					p->lastName, p->firstName, p->address, p->postNumber,
					&p->birthYear, &p->birthMonth, &p->birthDay,
					p->phoneNumber) != EOF);

	fclose(fp);

	// 最後余計に作っちゃうので消す
	free(pp->next);
	pp->next = NULL;

	return 0;
}

void printData(Data *root)
{
	Data *p = root->next;
	puts("名字\t名前\t住所\t郵便番号\t生年月日\t電話番号");
	while (p != NULL)
	{
		printf("%s\t%s\t%s\t%s\t%d/%d/%d\t%s\n",
			   p->lastName, p->firstName, p->address, p->postNumber,
			   p->birthYear, p->birthMonth, p->birthDay,
			   p->phoneNumber);
		p = p->next;
	}
}

void addData(Data *root)
{
	Data *p = root;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = newNode();
	p = p->next;

	printf("名字: ");
	scanf("%s", p->lastName);
	printf("名前: ");
	scanf("%s", p->firstName);
	printf("住所: ");
	scanf("%s", p->address);
	printf("郵便番号: ");
	scanf("%s", p->postNumber);
	printf("生年月日: ");
	scanf("%d/%d/%d", &p->birthYear, &p->birthMonth, &p->birthDay);
	printf("電話番号: ");
	scanf("%s", p->phoneNumber);
}

int deleteData(Data *root)
{
	char lastName[SIZE];
	char firstName[SIZE];
	printf("削除するデータの名字を入力してください: ");
	scanf("%s", lastName);
	printf("削除するデータの名前を入力してください: ");
	scanf("%s", firstName);

	Data *p = root;
	Data *pp = root;
	while (p != NULL)
	{
		if (strcmp(p->lastName, lastName) == 0 && strcmp(p->firstName, firstName) == 0)
		{
			pp->next = p->next;
			free(p);
			return 0;
		}
		pp = p;
		p = p->next;
	}
	puts("データが見つかりませんでした");
	return -1;
}

int fineData(Data *root)
{
	char lastName[SIZE];
	char firstName[SIZE];
	printf("検索するデータの名字を入力してください: ");
	scanf("%s", lastName);
	printf("検索するデータの名前を入力してください: ");
	scanf("%s", firstName);

	Data *p = root;
	while (p != NULL)
	{
		if (strcmp(p->lastName, lastName) == 0 && strcmp(p->firstName, firstName) == 0)
		{
			printf("名字: %s\n", p->lastName);
			printf("名前: %s\n", p->firstName);
			printf("住所: %s\n", p->address);
			printf("郵便番号: %s\n", p->postNumber);
			printf("生年月日: %d/%d/%d\n", p->birthYear, p->birthMonth, p->birthDay);
			printf("電話番号: %s\n", p->phoneNumber);
			return 0;
		}
		p = p->next;
	}
	puts("データが見つかりませんでした");
	return -1;
}

int saveData(Data *root)
{
	char fileName[SIZE];
	FILE *fp;

	printf("保存するファイル名を入力してください: ");
	scanf("%s", fileName);

	if ((fp = fopen(fileName, "w")) == NULL)
	{
		puts("ファイルを開けませんでした");
		return -1;
	}

	Data *p = root->next;
	while (p != NULL)
	{
		fprintf(fp, "%s,%s,%s,%s,%d/%d/%d,%s\n",
				p->lastName, p->firstName, p->address, p->postNumber,
				p->birthYear, p->birthMonth, p->birthDay,
				p->phoneNumber);
		p = p->next;
	}

	fclose(fp);

	return 0;
}

int main()
{
	char command;
	Data root = {0};

	puts("電話帳管理プログラム");
	puts("r: ファイルからデータを読み込む");
	puts("p: データを表示する");
	puts("s: データを保存する");
	puts("a: データを追加する");
	puts("d: データを削除する");
	puts("f: データを検索する");
	puts("e: 終了する");

	while (1)
	{
		printf("> ");
		scanf(" %c", &command);
		switch (command)
		{
		case 'r':
			readData(&root);
			break;
		case 'p':
			printData(&root);
			break;
		case 's':
			saveData(&root);
			break;
		case 'a':
			addData(&root);
			break;
		case 'd':
			deleteData(&root);
			break;
		case 'f':
			fineData(&root);
			break;
		case 'e':
			puts("see you!");
			return 0;
		default:
			break;
		}
	}
	return 0;
}
