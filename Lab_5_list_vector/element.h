#include "main.h"

class Element
{
	int data_int;
	double data_double;
	
	public:
		Element();
		Element(int, double);
		int getData_int() const;
		double getData_double() const;
		void setData_int(int);
		void setData_double(double);
		void Print() const;
};
