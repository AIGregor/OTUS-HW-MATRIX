#pragma once
#include <map>
#include "Matrix.h"
#include "Element.h"

template <typename T, T default_value>
class Row
{
public:
	Row();
	//~Row();

	Element<T, default_value>& operator[](size_t index);

	void setIndex(long indx) {
		lastIndex = indx;
	}

	size_t getSize() {
		return values.size();
	}

	void saveElement() {
		values[lastIndex] = defValue;
		Matrix<T, default_value> matrix;
		matrix.saveRow();
	}

private:
	std::map<size_t, Element<T, default_value>> values;
	Element<T, default_value> defValue;

	long lastIndex;
};

template<typename T, T default_value>
Row<T, default_value>::Row() : lastIndex(-1)
{
	values = std::map<size_t, Element<T, default_value> >();
	defValue.setValue(default_value);
}

template<typename T, T default_value>
inline Element<T, default_value>& Row<T, default_value>::operator[](size_t index)
{
	if (values.find(index) != values.end())
	{
		return  values[index];
	}

	defValue.current_row = this;
	lastIndex = index;
	return defValue;
}
