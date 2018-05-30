/* This program solves the problem of Eight Queens Puzzle using recursive backtracking algorithm
 */ 

#include <iostream>
#include <vector>

using std::vector;

static unsigned count = 0;

bool check(const unsigned & row, const vector<unsigned> position);
void search(const unsigned & row, vector<unsigned> position);

int main()
{
	printf("N Queens Problem.\nPlease input n:");
	size_t n;
	scanf("%d", &n);
	vector<unsigned> position(n);		// Place the k-th Queen at row k, column position[k].
	search(0, position);
	printf("%d Queens Problem: %d solutions\n", n, count);
	return 0;
}

bool check(const unsigned & row, const vector<unsigned> position)
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

void search(const unsigned & row, vector<unsigned> position)
{
	if (row >= position.size())
	{
		++count;
		return;
	}
	for (position[row] = 0; position.at(row) < position.size(); position[row]++)
	{
		if (check(row, position))
		{
			search(row + 1, position);
		}
	}
}

