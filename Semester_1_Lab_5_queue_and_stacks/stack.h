#include <iostream>

class Stack
{
	private:
		char* String;
		int current_symbol;
		Stack() {}
		int CheckingTheCorrectSequence() const;

	public:
		Stack(int);
		~Stack();
		int Push(char);
		char Pull();
		void Print() const;
};
