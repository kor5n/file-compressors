#include <stdio.h>

int main (int argc, char *argv[])
{
	char c;
	int i = -1;
	char prev_c = 'a';

	if (argc < 2)
	{
		printf("Provide a file to compress");
		return 1;
	}

	FILE *raw_file = fopen(argv[1], "r");

	if (!raw_file){
		perror("Error opening file");
		return 1;
	}

	while ((c = fgetc(raw_file)) != EOF)
	{
		if (prev_c == 'a')
		{
			prev_c = c;
		}
		if(c != prev_c)
		{
			printf("%d%c", i+1, prev_c);
			i = 0;
		}else
		{
			i++;
		}
		prev_c = c;
	}
	printf("%d%c", i+1, prev_c);
	fclose(raw_file);
	return 0;
}
