#include "main.h"

int main()
{
	char String[20];
	
	std::cout << "Введите выражение в постфиксной форме: " << std::endl;
	std::cin.getline(String, 20);	
	bool check_correct = CheckingTheCorrectSequence(String);

	if (check_correct)
	{
		Stack stack_expression(strlen(String));

		bool prev_letter = false;
		int count_symbol = 0;
		while (count_symbol < strlen(String))
		{
			if (count_symbol == 0)
			{
				stack_expression.Push('(');
				stack_expression.Push(String[count_symbol++]);
				prev_letter = true;
			}
			else if (prev_letter and String[count_symbol] >= 'a' and String[count_symbol] <= 'z')
			{
				stack_expression.Push(String[count_symbol + 1]);
				stack_expression.Push(String[count_symbol]);
				//Так как записал сразу 2 символа
				count_symbol += 2;
				stack_expression.Push(')');
				prev_letter = false;
			}
			else if (not(prev_letter) and String[count_symbol] >= 'a' and String[count_symbol] <= 'z')
			{
				if (String[count_symbol + 1] >= 'a' and String[count_symbol + 1] <= 'z')
				{
					stack_expression.Push(String[count_symbol + 3]);
					stack_expression.Push('(');
					stack_expression.Push(String[count_symbol]);
					stack_expression.Push(String[count_symbol + 2]);
					stack_expression.Push(String[count_symbol + 1]);
					stack_expression.Push(')');

					count_symbol += 4;
					prev_letter = false;
				}
				else
				{
					stack_expression.Push(String[count_symbol + 1]);
					stack_expression.Push(String[count_symbol]);
					count_symbol += 2;
					prev_letter = false;
				}
			}
		}

		stack_expression.Print();
	}
	else
		std::cout << "Постфиксное выражение не прошло проверку..." << std::endl;


	return 0;
}

bool CheckingTheCorrectSequence(const char* String)
{
	bool correct = true;

	int counter_letter = 0;
	int counter_arithmetic_sing = 0;

	if (strlen(String) != 0 && correct)
	{
		if (strlen(String) == 1 or strlen(String) == 2)
			correct = false;
		if (correct)
		{
			for (int i = 0; i < strlen(String); i++)
			{
				if (String[i] >= 'a' and String[i] <= 'z')
				{
					if (counter_arithmetic_sing != 0)
						counter_letter = 0;
					if (counter_letter < 2)
						counter_letter++;
					else
					{
						correct = false;
						break;
					}
					if (String[i + 1] == '\0')
					{
						correct = false;
						break;
					}
					counter_arithmetic_sing = 0;
				}
				else if (String[i] == '+' or String[i] == '-' or String[i] == '*' or String[i] == '/')
				{
					if (counter_arithmetic_sing < 2)
						counter_arithmetic_sing++;
					else
					{
						correct = false;
						break;
					}

					if (counter_arithmetic_sing == 2 && counter_letter == 1)
					{
						correct = false;
						break;
					}
				}
				else
				{
					correct = false;
					break;
				}
			}
		}	
	}
	else
		correct = false;

	return correct;
}
