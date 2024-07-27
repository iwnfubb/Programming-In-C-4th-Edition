#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define PRINT_EXEC(x) printf("-----------Exec %s ---------- \n", x)
#define IS_LOWER_CASE(x) (((x) >= 'a') && ((x) <= 'z'))
#define NUM 100

FILE *open_file(char *file_name, char *mode)
{
	FILE *in;
	if ((in = fopen(file_name, mode)) == NULL)
	{
		printf("Can't open %s for reading.\n", file_name);
		fclose(in);
	}
	return in;
}

void exec_6(void)
{
	PRINT_EXEC("6");
	char c = '0';
	char *inName = "Text_6_input.txt";
	do
	{
		int counter = 0;
		FILE *in;
		char *buffer = malloc(NUM);
		in = open_file(inName, "r");
		while (fgets(buffer, NUM, in) != NULL && counter < 20)
		{
			fputs(buffer, stdout);
			counter++;
		}
		fclose(in);
		printf("Enter q to quit.");
		fscanf(stdin, "%c", &c);
	} while (c != 'q');
}

void exec_5(void)
{
	PRINT_EXEC("5");
	int m, n, index;
	char c;
	FILE *in;
	char *inName = "Text_5_input.txt";
	printf("Enter m:\n");
	fscanf(stdin, "%i", &m);
	printf("Enter n:\n");
	fscanf(stdin, "%i", &n);

	in = open_file(inName, "r");
	index = 0;
	while ((c = getc(in)) != EOF)
	{
		if (index >= m && index <= n)
		{
			putc(c, stdout);
		}
		index++;

		if (c == '\n')
		{
			putc(c, stdout);
			index = 0;
		}
	}
	fclose(in);
}

void merge_file()
{
	FILE *in1, *in2;
	char *inName1 = "Text_4_input1.txt";
	char *inName2 = "Text_4_input2.txt";

	char *buffer = malloc(NUM);

	in1 = open_file(inName1, "r");
	in2 = open_file(inName2, "r");

	while (fgets(buffer, NUM, in1) != NULL)
	{
		fputs(buffer, stdout);
		if (fgets(buffer, NUM, in2) != NULL)
		{
			fputs(buffer, stdout);
		}
	}
	while (fgets(buffer, NUM, in2) != NULL)
		fputs(buffer, stdout);

	fclose(in1);
	fclose(in2);
}

int exec_4(void)
{
	PRINT_EXEC("4");
	merge_file();
}

int exec_3(void)
{
	PRINT_EXEC("3");
	FILE *in, *out;
	char *inName = "Text_3_input.txt";
	char *outName = "Text_3_output.txt";
	char c;

	in = open_file(inName, "r");
	out = open_file(inName, "w+");

	printf("Opened input file\n");

	while ((c = getc(in)) != EOF)
	{
		if (IS_LOWER_CASE(c))
		{
			putc(c - 32, out);
		}
		else
			putc(c, out);
	}
	fclose(in);
	fclose(out);
	return 0;
}

int main(void)
{
	exec_3();
	exec_4();
	exec_5();
	exec_6();
}
