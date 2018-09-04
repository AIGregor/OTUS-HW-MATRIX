#pragma once
#include <tuple>

template <typename T, T default_value>
class Element
{
public:
	Element();
	~Element();

	std::tuple<T>& operator[](long index);
};