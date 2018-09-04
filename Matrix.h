#pragma once
#include <vector>
#include "Element.h"

template <typename T, T default_value>
class Matrix
{
	using tuple_element = std::tuple<long, long, T>;

public:
	long size();
	tuple_element* begin();
	tuple_element* end();

	Element<T, default_value>& operator[](long index);

private:	
	std::vector<Element<T, default_value>> elements;
};

