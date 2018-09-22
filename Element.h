#pragma once
#include <map>
#include <iostream>
#include "Row.h"

template <typename T, T default_value>
class Element
{
public:
	Element();
	~Element() {};

	Element<T, default_value>& operator=(const T& val) {
		auto row = static_cast<Row<T, default_value>*>(current_row);

		if (val == default_value) 
		{
			row->deleteElement();
			return *this;
		}

		setValue(val);
		row->saveElement(*this);

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

template<typename T, T default_value>
std::ostream& operator<<(std::ostream& os, 
						const Element<T, default_value>& el) {
	os << el.getValue();
	return os;
}