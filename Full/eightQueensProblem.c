/*
 * This program solves the problem of Eight Queens Puzzle using recursive backtracking algorithm.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static unsigned	count = 0;

// Core functions
bool check(const unsigned position[], const unsigned n, const unsigned row);
void search(unsigned position[], const unsigned n, unsigned row, FILE *Data);
void saveSolution(const unsigned position[], const unsigned n, FILE *Data);

// Output functions
void printSolutions();
void printChessboard(unsigned n);

int main()
{
	unsigned n;						// Chessboard size.

	puts("N Queens Puzzle");

	printf("Please input the chessboard size:");
	fflush(stdout);
	scanf("%u", &n);
	printf("%d Queens Problem\n", n);

	clock_t start, finish;
	double duration;
	start = clock();

	// Allocate memory for position array to temporary store the solution.
	unsigned *position = (unsigned *)calloc(n, sizeof(unsigned));

	FILE *Data;
	Data = fopen("Data", "w");						// Creat a file to save those solutions.
	// Slove the N queens problem.
	unsigned row = 0;
	search(position, n, row, Data);

	free((void *)position);
	fclose(Data);

	printf("%d solutions!\n", count);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Total time taken by CPU: %lf\n", duration);

	printChessboard(n);

	return 0;
}

// Function definition
bool check(const unsigned position[], const unsigned n, const unsigned row)
{
	// Check is safe to place the queen.
	for (size_t i = 0; i < row; i++)
	{
		if (position[i] == position[row]							// Check columns.
			|| row - i == abs((int)(position[row] - position[i])))	// Check diagonal.
		{
			return false;
		}
	}
	return true;
}

void search(unsigned position[], const unsigned n, unsigned row, FILE *Data)
{
	// Search the chessboard.
	if (row >= n)
	{
		++count;
		saveSolution(position, n, Data);		// Save those solutions.
	}
	while (position[row] < n)
	{
		if (check(position, n, row))
		{
			search(position, n, ++row, Data);	// Search the next row.
			position[row--] = 0;				// Backtracking.
		}
		++position[row];						// Try the next position.
	}
}

void saveSolution(const unsigned position[], const unsigned n, FILE *Data)
{
	// Store the solutions to the Data file.
	for (size_t i = 0; i < n; i++)
	{
		fprintf(Data, "%2u ", position[i]);
	}
	fputs("", Data);
}

void printSolutions()
{
	// Print the Data file.
	int ch;
	FILE *fr;
	fr = fopen("Data", "r");
	ch = getc(fr);
	while (ch != EOF)
	{
		putchar(ch);
		ch = getc(fr);
	}
	fclose(fr);
}

void printChessboard(unsigned n)
{
	// Print the chessboard with n Queens.
	unsigned position;
	FILE *fr;
	fr = fopen("Data", "r");

	for (size_t i = 0; i < count; i++)
	{
		for (size_t row = 0; row < n; row++)
		{
			fscanf(fr, "%2d ", &position);
			for (size_t column = 0; column < n; column++)
			{
				printf(column == position ? "|Q" : "| ");
			}
			puts("|");
		}
		puts("");
	}
}

