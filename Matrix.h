#pragma once
#include <map>
#include "Row.h"

template <typename T, T default_value>
class Matrix
{
public:
	Matrix();

	size_t size();
	std::tuple<long, long, T>* begin();
	std::tuple<long, long, T>* end();

	Row<T, default_value>& operator[](size_t index);

	void saveRow() {
		if (lastIndex < 0)
			return;

		rows[lastIndex] = defValue;		
		lastIndex = -1;
	}

private:	
	std::map<size_t, Row<T, default_value>> rows;

	Row<T, default_value> defValue;
	long lastIndex;
};

template<typename T, T default_value>
inline Matrix<T, default_value>::Matrix() : lastIndex(-1)
{
}

template<typename T, T default_value>
size_t Matrix<T, default_value>::size()
{
	size_t size = 0;
	for (auto& row : rows)
	{
		size += row.second.getSize();
	}
	return size;
}

template<typename T, T default_value>
std::tuple<long, long, T>* Matrix<T, default_value>::begin()
{
	return nullptr;
}

template<typename T, T default_value>
std::tuple<long, long, T>* Matrix<T, default_value>::end()
{
	return nullptr;
}

template<typename T, T default_value>
Row<T, default_value>& Matrix<T, default_value>::operator[](size_t index)
{
	if (index < 0)
		return;

	if (rows.find(index) != rows.end() && index >=0)
	{
		return rows[index];
	}

	defValue.current_matrix = this;
	lastIndex = index;

	return defValue;
}