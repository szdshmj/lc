#include "../inc.h"

int minPathSum(int** grid, int gridRowSize, int gridColSize) {

	//dump_int_int_m_n(grid, gridRowSize, gridColSize);

	for(int i = 1; i < gridColSize; i++)
		grid[0][i] += grid[0][i - 1];

	for(int i = 1; i < gridRowSize; i++) 
		grid[i][0] += grid[i - 1][0];

	//dump_int_int_m_n(grid, gridRowSize, gridColSize);
	if(gridRowSize > 1 && gridColSize > 1) {

		for(int i = 1; i < gridRowSize; i++) {
			for(int j = 1; j < gridColSize; j++) {

				int min = (grid[i - 1][j] < grid[i][j - 1]) ?  grid[i - 1][j] : grid[i][j - 1];
				grid[i][j] += min;
			}
		}
	}
	//dump_int_int_m_n(grid, gridRowSize, gridColSize);
	return grid[gridRowSize - 1][gridColSize - 1];
}

int main()
{
	int **data;
	int a[][3] = 
	{
		{1, 3, 1},
		{1, 5, 1},
		{4, 2, 1}		
	};

	data = make_int_int_m_n(3, 3, (int *) a);

	printf("%d\n", minPathSum(data, 3, 3));
	return 0;
}
