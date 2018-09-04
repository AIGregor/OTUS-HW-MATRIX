#pragma once
#include <tuple>

template <typename T, T default_value>
class Element
{
public:
	Element();
	~Element();

	T& operator[](long index);
	int get_i() { return i; };
	int get_j() { return j; };
	T& get_value() { return value; };

	void set_i(int i);
	void set_j(int j);
	void set_value(const T value);
private:
	int i;
	int j;
	T value;
};