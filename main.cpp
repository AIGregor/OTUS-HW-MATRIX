#pragma once
#include <iostream>
#include <tuple>
#include <cassert>

#include "Matrix.h"

int main()
{
	Matrix<int, -1> matrix; // ����������� ������� int ��������� ���������� -1

	assert(matrix.size() == 0); // ��� ������ ��������

	auto a = matrix[0][0];

	assert(a == -1);
	assert(matrix.size() == 0);

	matrix[100][100] = 314;

	assert(matrix[100][100] == 314);
	assert(matrix.size() == 1);

	// ��������� ���� ������
	// 100100314
	for (auto c : matrix)
	{
		int x;
		int y;
		int v;
		std::tie(x, y, v) = c;
		std::cout << x << y << v << std::endl;
	}

	return 0;
}