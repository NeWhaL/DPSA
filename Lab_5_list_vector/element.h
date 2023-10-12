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
		void Print() const;
		Element operator = (Element);
};
