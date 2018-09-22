#pragma once
#include <map>
#include "Matrix.h"
#include "Element.h"

template <typename T, T default_value>
class Row
{
public:
	Row();
	~Row() {};

	Element<T, default_value>& operator[](size_t index);

	auto begin() {
		return std::begin(values);
	};
	auto end() {
		return std::end(values);
	};

	void setIndex(long indx) {
		lastIndex = indx;
	}

	size_t getSize() {
		return values.size();
	}

	void saveElement(Element<T, default_value>& element) {
		if (lastIndex < 0)
			return;

		values[lastIndex] = element;
		auto matrix = static_cast<Matrix<T, default_value>*>(current_matrix);
		matrix->saveRow(*this);

		lastIndex = -1;
	}

	void deleteElement() {
		if (lastIndex < 0)
			return;

		values.erase(lastIndex);

		auto matrix = static_cast<Matrix<T, default_value>*>(current_matrix);
		matrix->deleteRow();

		lastIndex = -1;		
	}

	size_t getIndex() {
		return values.begin()->first;
	}

	T getValue() {
		return values.begin()->second.getValue();
	}

	void clear() {
		values.clear();
	}

public:
	void* current_matrix;

private:
	std::map<size_t, Element<T, default_value>> values;
	Element<T, default_value> defValue;

	long lastIndex;
};

template<typename T, T default_value>
Row<T, default_value>::Row() : 
	lastIndex(-1)
{
	values = std::map<size_t, Element<T, default_value> >();
}

template<typename T, T default_value>
inline Element<T, default_value>& Row<T, default_value>::operator[](size_t index)
{
	if (index < 0)
		assert(false);

	lastIndex = index;
	if (values.find(index) != values.end())
	{
		values[index].current_row = this;
		return values[index];
	}

	defValue.current_row = this;
	defValue.setValue(default_value);

	return defValue;
}
