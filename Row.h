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
		if (lastIndex < 0)
			return;

		values[lastIndex] = defValue;
		auto matrix = static_cast<Matrix<T, default_value>*>(current_matrix);
		matrix->saveRow();

		lastIndex = -1;
		defValue.setValue(default_value);
	}

private:
	std::map<size_t, Element<T, default_value>> values;
	Element<T, default_value> defValue;

	void* current_matrix;
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
	if (index < 0)
		return;

	if (values.find(index) != values.end())
	{
		return  values[index];
	}

	defValue.current_row = this;
	lastIndex = index;

	return defValue;
}
