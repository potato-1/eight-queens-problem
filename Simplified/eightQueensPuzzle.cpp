// Eight queens problem using backtracking recurison.
// 

#include <iostream>

#define N 8

static unsigned count = 0;
static unsigned position[N] = { 0 };		// Place the kth Queen at row k, column position[k].

bool check(const unsigned & row);
void search(unsigned & row);

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

void search(unsigned & row)
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
		}
		++position[row];
	}
	position[row--] = 0;		// Backtrack
}

