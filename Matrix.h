#pragma once
#include <vector>
#include "Element.h"

template <typename T, T default_value>
class Matrix
{
public:
	T size();
	T* begin();
	T* end();

	Element<T, default_value>& operator[](long index);

private:	
	std::vector<Element<T, default_value>> elements;
};

