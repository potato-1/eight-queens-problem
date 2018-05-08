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

// Output functions
void printPosition(const unsigned position[], const unsigned n, FILE *Data);
void printChessboard(const unsigned position[], const unsigned n);

int main()
{
	unsigned n;										// Chessboard size.

	FILE *Data;
	Data = fopen("Data.txt", "w+");					// File to save those solutions.

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

	// Slove the N queens problem.
	unsigned row = 0;
	search(position, n, row, Data);
	printf("%d solutions!\n", count);

	free((void *)position);
	fclose(Data);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Total time taken by CPU: %lf\n", duration);

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
		printPosition(position, n, Data);		// Output the solution.
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

void printPosition(const unsigned position[], const unsigned n, FILE *Data)
{
	// Store the solutions to the Data file.
	for (size_t i = 0; i < n; i++)
	{
		fprintf(Data, "%3u ", position[i]);
	}
	fprintf(Data, "\n");
}

void printChessboard(const unsigned position[], const unsigned n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			printf(position[i] == j ? "|Q" : "| ");
		}
		puts("|");
	}
	puts("");
}

