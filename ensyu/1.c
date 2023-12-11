#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char **a, char **b)
{
	char *tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	FILE *input;
	FILE *output;

	char inputName[256] = {0};
	char outputName[256] = {0};

	scanf("%s %s", inputName, outputName);

	input = fopen(inputName, "r");

	int tangoCount = 0;

	fscanf(input, "%d", &tangoCount);

	char **tango;
	char buf[256];

	tango = (char **)malloc(sizeof(char *) * tangoCount);

	for (int i = 0; i < tangoCount; i++)
	{
		// init buf
		memset(buf, 0, sizeof(buf));

		// read
		fscanf(input, "%s", buf);

		// malloc
		tango[i] = (char *)malloc(sizeof(char) * (strlen(buf) + 1));

		// copy
		strcpy(tango[i], buf);
	}

	// sort tango
	for (int i = 0; i < tangoCount; i++)
	{
		for (int j = 0; j < tangoCount - 1; j++)
		{
			if (strcmp(tango[j], tango[j + 1]) > 0)
			{
				swap(tango[j], tango[j + 1]);
			}
		}
	}

	output = fopen(outputName, "w");

	for (int i = 0; i < tangoCount; i++)
	{
		fprintf(output, "%s\n", tango[i]);
	}
}