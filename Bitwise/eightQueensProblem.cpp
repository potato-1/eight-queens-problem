// This program solves the problem of Eight Queens Puzzle using recursive backtracking algorithm
// in bitwise operations.
// 

#include <cstdio>
#include <ctime>

static unsigned done = 1;
static unsigned count = 0;

void search(const unsigned column, const unsigned left_diagonal, const unsigned right_diagonal);

int main()
{
	size_t chessboard_size;
	printf("Please input the chessboard size:");
	scanf("%zd", &chessboard_size);
	--(done <<= chessboard_size);

	printf("%zd queens problem\n", chessboard_size);
	clock_t start = clock();
	search(0, 0, 0);
	clock_t finish = clock();
	double duration = (double)((finish - start) / CLOCKS_PER_SEC);
	printf("Find %u solutions in %lf clocks\n", count, duration);

	return 0;
}

void search(const unsigned column, const unsigned left_diagonal, const unsigned right_diagonal)
{	
	if (column != done)
	{
		int state = done & ~(column | left_diagonal | right_diagonal);
		while (state)
		{
			const unsigned position = state & -state;
			state -= position;
			search(column + position, (left_diagonal + position) << 1, (right_diagonal + position) >> 1);
		}
	}
	else
	{
		++count;
	}
}
