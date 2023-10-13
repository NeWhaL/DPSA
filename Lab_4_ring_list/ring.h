#include <iostream>

using namespace std;

class ring
{
	struct element
	{
		double data;
		element* next;
		element* prev;
	};
	element* head;
	int amountElement;

	public:
		ring(): amountElement(0), head(nullptr) {};
		~ring()
		{
			DeleteList();
		}
		void DeleteElement();
		void DeleteElement(int);
		void DeleteList();	
		void DeleteData(double);
		void GoNext();
		void GoPrev();
		void PushNext(double);
		void PushPrev(double);
		void SearchElement(double) const;
		void Print();
};
