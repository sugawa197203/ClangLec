#include <stdio.h>

int main()
{
	// char c;
	// scanf("%s", &c);
	// printf("%c\n", c);
	// printf("%c\n", *((&c) + 10));

	// char aaa[100];
	// char bbb[100];
	// char ccc[100];
	// int a, b, c;

	char str[100];
	char str2[100];
	char str3[100];
	char str4[100];

	// scanf("%s%d%s%d%s%d", aaa, &a, bbb, &b, ccc, &c);
	// A111BB22CCC3
	// !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
	// scanf("%[!-/]%[:-@]%[\[-`]%[{-~]", str1, str2, str3, str4);
	// printf("s1: %s\n", str1);
	// printf("s2: %s\n", str2);
	// printf("s3: %s\n", str3);
	// printf("s4: %s\n", str4);

	scanf("%*[^a-zA-Z]%[a-zA-Z]%*[^a-zA-Z\n]", str);
	printf("s1: %s\n", str);
}