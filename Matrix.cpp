#include "Matrix.h"

template<typename T, T default_value>
inline size_t Matrix<T, default_value>::size()
{	
	return rows.size;
}

template<typename T, T default_value>
Row<T, default_value>::tuple_row* Matrix<T, default_value>::begin()
{
	return nullptr;
}

template<typename T, T default_value>
Row<T, default_value>::tuple_row* Matrix<T, default_value>::end()
{
	return nullptr;
}

template<typename T, T default_value>
Row<T, default_value>& Matrix<T, default_value>::operator[](long index)
{
	if ()

	return std::get<0>(rows[index]);
}