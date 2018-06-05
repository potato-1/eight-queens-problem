// This program solves the problem of Eight Queens Puzzle using recursive backtracking algorithm

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 8

static unsigned count = 0;
static unsigned position[N];		// Place the k-th Queen at row k, column position[k].

bool check(const unsigned row);
void search(const unsigned row);

int main() 
{
	clock_t start, finish;

	printf("%d queens problem:\n", N);
	start = clock();
	search(0);
	finish = clock();
	printf("Find %d soluntions in %ld clocks", count, finish - start);

	return 0;
}

bool check(const unsigned row) 
{
	for (size_t i = 0; i < row; i++) 
	{
		if (position[i] == position[row] || row - i == abs((int)(position[row] - position[i])))
		{
			return false;
		}
	}
	return true;
}

void search(const unsigned row) 
{
	if (row < N) 
	{
		for (position[row] = 0; position[row] < N; position[row]++)
		{
			if (check(row))
			{
				search(row + 1);
			}
		}
	}
	else
	{
		++count;
	}
}

