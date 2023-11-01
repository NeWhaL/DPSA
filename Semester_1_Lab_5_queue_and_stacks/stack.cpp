#include "stack.h"

Stack::Stack(int size_string): current_symbol(0)
{
	String = new char[size_string * 2];	
}

Stack::~Stack()
{
	delete[] String;
}

char Stack::Pull()
{
	current_symbol--;
	return String[current_symbol];
}

int Stack::Push(char symbol)
{
	int error = 0;

	if ((symbol >= 'a' and symbol <= 'z') or symbol == '+' or symbol == '-' or symbol == '*' or symbol == '/' or symbol == '(' or symbol == ')')	
	{
		String[current_symbol] = symbol;
		current_symbol++;
	}
	else error = 1;

	return error;		
}

void Stack::Print() const
{
	std::cout << "Строка в стеке: " << String << std::endl;
}
