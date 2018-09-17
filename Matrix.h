#pragma once
#include <vector>
#include "Row.h"

template <typename T, T default_value>
class Matrix
{
	//using tuple_Row = std::tuple<long, long, T>;

public:
	size_t size();
	Row<T, default_value>::tuple_row* begin();
	Row<T, default_value>::tuple_row* end();

	Row<T, default_value>& operator[](long index);

private:	
	std::vector<Row<T, default_value>> rows;
};

