#include <iostream>

using namespace std;

class List;

int AmountElementInList();
void NewList(const List&, List&, int);

class List
{
	friend void NewList(const List&, List&, int);
	private:
		struct Element
		{
			int data;
			Element* next;
		};
		Element* head;
		Element* tail;
		
	public:
		List();
		List(int);
		void Push(int);
		void PushHead(int);
		void Sort();
		void Delete();
		void Print() const;
};
