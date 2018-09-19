#pragma once
#include <map>
#include "Row.h"

template <typename T, T default_value>
class Element
{
public:
	Element();
	//~Element();

	Element<T, default_value>& operator=(const T& val) {
		setValue(val);

		auto row = static_cast<Row<T, default_value>*>(current_row);
		row->saveElement();

		return *this;
	}

	bool operator==(const T& value) const {
		return getValue() == value;
	}

	void setValue(const T& val) {
		value = val;
	}

	const T getValue() const {
		return value;
	}

public:
	void* current_row;

private:
	T value;	
};

template<typename T, T default_value>
inline Element<T, default_value>::Element()
{
}