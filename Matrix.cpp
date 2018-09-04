#include "Matrix.h"

template<typename T, T default_value>
inline T Matrix<T, default_value>::size()
{
	return T();
}

template<typename T, T default_value>
T* Matrix<T, default_value>::begin()
{
	return nullptr;
}

template<typename T, T default_value>
T* Matrix<T, default_value>::end()
{
	return nullptr;
}

template<typename T, T default_value>
Element<T, default_value>& Matrix<T, default_value>::operator[](long index)
{
	return std::get<0>(elements[index]);
}