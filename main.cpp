#pragma once
#include <iostream>
#include <tuple>
#include <cassert>

#include "Matrix.h"

#define MAX_ZISE 9

void test() {

	Matrix<int, -1> matrix; // бесконечная матрица int заполнена значениями -1

	assert(matrix.size() == 0); // все ячейки свободны

	auto a = matrix[0][0];

	assert(a == -1);
	assert(matrix.size() == 0);

	matrix[100][100] = 314;

	assert(matrix[100][100] == 314);
	assert(matrix.size() == 1);

	matrix[100][10] = 457;

	assert(matrix[100][10] == 457);
	assert(matrix.size() == 2);

	matrix[100][100] = -1;
	assert(matrix[100][100] == -1);
	assert(matrix.size() == 1);

	// выведется одна строка
	// 100100314
	for (auto c : matrix)
	{
		int x = c.first;
		for (auto e : c.second)
		{
			int y = e.first;
			int v = e.second.getValue();
			//std::tie(x, y, v) = c;
			std::cout << x << y << v << std::endl;
		}
	}
}

int main()
{
	Matrix<int, 0> matrix; // бесконечная матрица int заполнена значениями -1

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

	for (int i = 1; i < MAX_ZISE; ++i)
	{
		for (int j= 1; j < MAX_ZISE; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << matrix.size() << std::endl;

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