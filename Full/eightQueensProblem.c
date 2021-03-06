/* nQueens.cpp : this program solves the problem of N Queens Puzzle using recursive backtracking algorithm.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BUFSIZE 16

static unsigned n = 8;
static unsigned count;
const char fileName[] = "data";
FILE *data;

void prompt();
const char* getOption();
bool jump(const char* response);

bool check(const unsigned row, const unsigned position[]);
void search(const unsigned row, unsigned position[]);
void solve();

void saveSolution(unsigned position[]);
void printShort();
void printBoard();

void(*funcs[])() = { solve,printShort,printBoard,prompt,NULL };

int main()
{
	const char* option;
	bool flag = true;
	solve();
	prompt();
	
	while (flag)
	{
		option = getOption();
		flag = jump(option);
	}
	return 0;
}

void prompt()
{
	puts("Choose an option:");
	puts("1.Solve");
	puts("2.Print in short format");
	puts("3.Print in board format");
	puts("4.Help");
	puts("q.Quit");
}

const char* getOption()
{
	printf(">>");
	fflush(stdout);
	static char response[BUFSIZE];
	fgets(response, BUFSIZE, stdin);

	if (response[0] == '\n')
	{
		fgets(response, BUFSIZE, stdin);
	}
	return response;
}

bool jump(const char *response)
{
	char code = response[0];
	if (code == 'q' || code == 'Q')
	{
		remove(fileName);
		return 0;
	}

	int funcLength = 0;
	while (funcs[funcLength] != NULL)
	{
		funcLength++;
	}

	int i = (int)code - '1';
	if (i < 0 || i >= funcLength)
	{
		puts("Invalid choice\n");
		prompt();
		return 1;
	}
	else
	{
		funcs[i]();
		return 1;
	}
}

void printShort()
{
	data = fopen(fileName, "r");
	char ch = getc(data);
	while (ch != EOF)
	{
		putchar(ch);
		ch = getc(data);
	}
	fclose(data);
}

void printBoard()
{
	unsigned position;
	data = fopen(fileName, "r");

	for (size_t i = 0; i < count; i++)
	{
		for (size_t row = 0; row < n; row++)
		{
			fscanf(data, "%2d ", &position);
			for (size_t column = 0; column < n; column++)
			{
				printf(column == position ? "|Q" : "| ");
			}
			puts("|");
		}
		puts("");
	}
	fclose(data);
}

bool check(const unsigned row, const unsigned position[])
{
	for (size_t i = 0; i < row; i++)
	{
		if (position[row] == position[i] ||
			row - i == abs((int)(position[row] - position[i])))
		{
			return false;
		}
	}
	return true;
}

void search(const unsigned row, unsigned position[])
{
	if (row < n)
	{
		for (position[row] = 0; position[row] < n; position[row]++)
		{
			if (check(row, position))
			{
				search(row + 1, position);
			}
		}
	}
	else
	{
		++count;
		saveSolution(position);
	}
}

void solve()
{
	printf("Please input the board size:");
	fflush(stdout);
	scanf("%d", &n);

	clock_t start = clock();
	unsigned* position = (unsigned*)calloc(n, sizeof(unsigned));
	data = fopen(fileName, "w+");

	printf("Solving %d Queens Problem...", n);
	search(0, position);

	free(position);
	fclose(data);

	clock_t finish = clock();

	double duration = (double)((finish - start) / CLOCKS_PER_SEC);
	printf("\nfind %u soultions in %lf seconds.\n", count, duration);
}

void saveSolution(unsigned position[])
{
	for (size_t index = 0; index < n; index++)
	{
		fprintf(data, "%2d ", position[index]);
	}
	fprintf(data, "\n");
}