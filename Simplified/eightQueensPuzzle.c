/*
 * This program solves the problem of Eight Queens Puzzle using recursive backtracking algorithm
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

static unsigned count = 0;
static unsigned position[N];		// Place the k-th Queen at row k, column position[k].

bool check(const unsigned row);
void search(unsigned row);

int main() 
{
	printf("%d queens problem:\n", N);
	search(0);
	printf("%d soluntions!", count);
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

void search(unsigned row) 
{
	if (row >= N) 
	{
		++count;
	}
	while (position[row] < N)
	{
		if (check(row))
		{
			search(++row);
			position[row--] = 0;			// Backtracking
		}
		++position[row];
	}	
}

