// This program solves the Eight Queens Puzzle using recursive backtracking algorithm
// 
// It is very inefficient unsing vector here, using C-Style array is a better choice.
  
#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>

using std::vector;

static unsigned count = 0;

bool check(const unsigned row, const vector<unsigned> position);
void search(const unsigned row, vector<unsigned> position);

int main()
{
	size_t chessboard_size;
	printf("Please input the chessboard size:");
	scanf("%zd", &chessboard_size);
	vector<unsigned> position(chessboard_size);		// Place the k-th Queen at row k, column position[k].

	printf("%zd queens problem\n", chessboard_size);
	clock_t start = clock();
	search(0, position);
	clock_t finish = clock();
	printf("Find %d solutions in %ld clocks", count, finish - start);

	return 0;
}

bool check(const unsigned row, const vector<unsigned> position)
{
	for (size_t i = 0; i < row; i++)
	{
		if (position.at(i) == position.at(row) || row - i == abs((int)(position.at(row) - position.at(i))))
		{
			return false;
		}
	}
	return true;
}

void search(const unsigned row, vector<unsigned> position)
{
	size_t length = position.size();
	if (row < length)
	{
		for (position[row] = 0; position.at(row) < length; position[row]++)
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
	}
}

