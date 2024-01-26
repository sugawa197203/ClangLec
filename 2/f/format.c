#include <stdio.h>

int main()
{
	char buf[256] = {0};
	scanf("%*[a-zA-Z]", buf);
	printf("%s\n", buf);
}