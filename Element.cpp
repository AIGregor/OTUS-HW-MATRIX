#include "Element.h"

template<typename T, T default_value>
inline Element<T, default_value>::Element()
{
}

template<typename T, T default_value>
inline Element<T, default_value>::~Element()
{
}

template<typename T, T default_value>
T& Element<T, default_value>::operator[](long index)
{
	return value;
	// TODO: insert return statement here
}
