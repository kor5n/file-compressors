#include <stdio.h>

int main (int argc, char *argv[])
{
	char c;
	int i = 0;
	
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
		putchar(c);
		i++;
	}

	fclose(raw_file);
	return 0;
}
