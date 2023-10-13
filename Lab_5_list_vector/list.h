#include "main.h"
#include "element.h"

class Queue
{
	const int memory_increment_and_decrement;
	int max_amount_element;
	int current_amount_element;	
	Element* Arr_element;

	public:
		Queue();
		~Queue();
		int Size() const;
		void Push(Element);
		Element* PullAmountElement(int&);
		Element Pull();
		void AddElements(Element*&, int);
		void LookLastElement() const;
		void Print() const;
		bool IsEmpty() const;
		void DeleteQueue();	
};
