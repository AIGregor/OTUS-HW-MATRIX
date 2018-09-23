#pragma once
#include <map>
#include "Row.h"

template <typename T, T default_value>
class Matrix
{
public:
	Matrix();
	~Matrix() {};

	size_t size();
	auto begin();
	auto end();

	Row<T, default_value>& operator[](size_t index);

	void saveRow(Row<T, default_value>& row) {
		if (lastIndex < 0)
			return;

		rows[lastIndex] = row;

		lastIndex = -1;
		defValue.clear();
	}

	void deleteRow() {
		if (lastIndex < 0)
			return;

		if (rows[lastIndex].getSize() == 0) {
			rows.erase(lastIndex);
		}
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
auto Matrix<T, default_value>::begin()
{
	return std::begin(rows);
}

template<typename T, T default_value>
auto Matrix<T, default_value>::end()
{
	return std::end(rows);
}

template<typename T, T default_value>
inline Row<T, default_value>& Matrix<T, default_value>::operator[](size_t index)
{
	if (index < 0)
		assert(false);

	lastIndex = index;
	if (rows.find(index) != rows.end() && index >=0)
	{
		rows[index].current_matrix = this;
		return rows[index];
	}

	defValue.current_matrix = this;
	return defValue;
}