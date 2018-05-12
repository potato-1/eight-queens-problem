/*
 * This program solves the problem of Eight Queens Puzzle using recursive backtracking algorithm
 */ 

#include <iostream>

#define N 8

static unsigned count = 0;
static unsigned position[N] = { 0 };		// Place the k-th Queen at row k, column position[k].

bool check(const unsigned & row);
void search(const unsigned & row);

int main()
{
	std::cout << N << " queens problem:" << std::endl;
	unsigned row = 0;
	search(row);
	std::cout << count << " solutions!" << std::endl;
	return 0;
}

bool check(const unsigned & row)
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

void search(const unsigned & row)
{
	if (row >= N)
	{
		++count;
	}
	for (position[row] = 0; position[row] < N; position[row]++)
	{
		if (check(row))
		{
			search(row + 1);
		}
	}
}

