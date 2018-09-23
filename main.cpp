#pragma once
#include <iostream>
#include <cassert>
#include "Matrix.h"

#define MAX_ZISE 9

int main()
{
	Matrix<int, 0> matrix;
	
	// main Diagonal
	int i = 0;
	while (i <= MAX_ZISE)
	{
		matrix[i][i] = i;
		++i;
	}	
	// secondary diagonal
	--i;
	while (i >= 0)
	{
		matrix[MAX_ZISE - i][i] = i;
		--i;
	}

	// print matrix 8x8
	for (int i = 1; i < MAX_ZISE; ++i)
	{
		for (int j= 1; j < MAX_ZISE; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	// output matrix full cell count
	std::cout << matrix.size() << std::endl;
	
	// output full cells
	for (auto r : matrix)
	{
		int x = r.first;
		for (auto e : r.second)
		{
			int y = e.first;
			int v = e.second.getValue();
			std::cout << x << y << v << std::endl;
		}
	}
	return 0;
}