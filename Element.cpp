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
std::tuple<T>& Element<T, default_value>::operator[](long index)
{
	// TODO: insert return statement here
}
