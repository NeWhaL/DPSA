#include "element.h"

Element::Element(): data_int(0), data_double(0) {};

Element::Element(int data_i, double data_d): data_int(data_i), data_double(data_d) {};

void Element::Print() const
{
	cout << "Element:	data_int == " << getData_int() << "		" << "data_double == " << getData_double() << endl;
}

int Element::getData_int() const
{
	return data_int;
}

double Element::getData_double() const
{
	return data_double;
}

void Element::setData_int(int data_i)
{
	data_int = data_i;
}

void Element::setData_double(double data_d)
{
	data_double = data_d;
}

