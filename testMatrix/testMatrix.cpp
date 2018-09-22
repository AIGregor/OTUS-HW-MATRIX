// testMatrix.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "gtest/gtest.h"

#include "../Matrix.h"

class CMatrixTest : public ::testing::Test {
};

TEST_F(CMatrixTest, CheckSize)
{
	Matrix<int, -1> matrix; // бесконечная матрица int заполнена значениями -1
	ASSERT_TRUE(matrix.size() == 0);
}

TEST_F(CMatrixTest, CheckAddValue)
{
	Matrix<int, -1> matrix; // бесконечная матрица int заполнена значениями -1
	matrix[100][100] = 314;

	ASSERT_TRUE(matrix[100][100] == 314);
	ASSERT_TRUE(matrix.size() == 1);

	matrix[100][10] = 457;

	ASSERT_TRUE(matrix[100][10] == 457);
	ASSERT_TRUE(matrix.size() == 2);	
}

TEST_F(CMatrixTest, CheckAddRemoveValue)
{
	Matrix<int, -1> matrix; // бесконечная матрица int заполнена значениями -1
	matrix[100][100] = 314;

	ASSERT_TRUE(matrix[100][100] == 314);
	ASSERT_TRUE(matrix.size() == 1);

	matrix[100][100] = -1;
	ASSERT_TRUE(matrix[100][100] == -1);
	ASSERT_TRUE(matrix.size() == 0);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

