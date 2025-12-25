#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char iter[50] = "";
	char c; 

	if (argc < 2)
	{
		printf("Provide a file to decode");
		return 1;
	}

	FILE *raw_file = fopen(argv[1], "r");

	if (!raw_file)
	{
		perror("Error opening file");
		return 1;
	}
	while((c = fgetc(raw_file)) != EOF)
	{

		if (isdigit(c))
		{
			size_t len = strlen(iter);
			if (len + 1 < sizeof(iter))
			{
				iter[len] = c;
				iter[len + 1] = '\0';
			}
		}else
		{	
			int count = atoi(iter);
			for(int i =0; i<count; i++)
			{
				putchar(c);
			}
			iter[0] = '\0';
		}
	}
	printf("\n");
	fclose(raw_file);
	return 0;
}
