#include "Row.h"

template<typename T, T default_value>
inline Row<T, default_value>::Row()
{
}

template<typename T, T default_value>
inline Row<T, default_value>::~Row()
{
}

template<typename T, T default_value>
T& Row<T, default_value>::operator[](long index)
{
	return value;
	// TODO: insert return statement here
}
