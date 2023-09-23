#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int AMOUNT_ELEM_STR = 200;
const char numbers[11] = "0123456789";

/*В некоторых строках текстового файла имеются выражения, состоящие из двух целых чисел,
 * разделенных знаком арифметической операции ('+', '-', '*', '/'). В строке перед выражением и
 * после него могут находиться произвольные символы. Требуется заменить все выражения на результат
 * их расчёта.*/

void txt_read_text(const char[], char[]);
void edit_processing(const char[], char[]);
const char* equation(const char[], float*);

int main()
{
	const char filename[30] = "text.txt";	
	char str[AMOUNT_ELEM_STR];
	char ready_text[AMOUNT_ELEM_STR];
	
	txt_read_text(filename, str);
	edit_processing(str, ready_text);

	return 0;
} 

void edit_processing(const char text[], char ready_text[]) 
{ 
	const char* num_ptr = text; 
	const char* start_text_ptr = text; 
	char* ready_text_ptr = ready_text; 

	while ((num_ptr = strpbrk(num_ptr, numbers)) != nullptr) 
	{ 
		int pointer_difference = num_ptr - start_text_ptr; 
		strncpy(ready_text_ptr, start_text_ptr, pointer_difference);
		
		ready_text_ptr += pointer_difference;
		
		//Передвижение указателя первой цифры на начало следующего фрагмента текста и решение выражения
		float number;
		num_ptr = equation(num_ptr, &number);
		
		//Перенос числа в строку
		char str_num[10];
		snprintf(str_num, 9, "%.1f", number);
		
		//Поиск конца числа в строке
		char* str_num_end;
		for (int i = 0; i < 10; i++)
		{
			if (str_num[i] == '\0')
			{
				str_num_end = str_num + i;
				break;
			}
		}
		//Скопировать число в итоговый текст
		strcpy(ready_text_ptr, str_num);
		//Сдвинуть в итоговом тексте указатель на длину числа
		ready_text_ptr += str_num_end - str_num;
		//Записать вместо '\0' символ пробела
		*ready_text_ptr = ' ';
		ready_text_ptr++;

		//перемещение указателя начального текста с начала скопированного фрагмента в конец этого фрагмента
		start_text_ptr = num_ptr;
	 }
	strcpy(ready_text_ptr, start_text_ptr);	

	cout << "Конечный вид текста: " << ready_text << endl;
}

const char* equation(const char* start_equation, float* number)
{
	const char* ptr_equation = start_equation;
	char str_equation[20];

	while (!(*ptr_equation >= 'A' && *ptr_equation <= 'Z') && !(*ptr_equation >= 'a' && *ptr_equation <='z'))
	{
		if (*ptr_equation == '\0')
			break;
		ptr_equation++;
	}
	
	int length_equation = ptr_equation - start_equation;
	strncpy(str_equation, start_equation, length_equation);	
	str_equation[length_equation] = '\0';

	char arithmetic_sing;
	int num_1 = 0, num_2 = 0;
	bool num_switch = true;

	for (int i = 0; str_equation[i] != '\0'; i++)
	{
		if (str_equation[i] == ' ') continue;
		else if (str_equation[i] >= '0' && str_equation[i] <= '9')
		{
			if (num_switch)
			{
				num_1 = num_1 * 10 + str_equation[i] - 48;
			}
			else
			{
				num_2 = num_2 * 10 + str_equation[i] - 48;
			}
		}
		else if (str_equation[i] == '+' || str_equation[i] == '-' || str_equation[i] == '/' || str_equation[i] == '*')
		{
			arithmetic_sing = str_equation[i];
			num_switch = false;
		}
	}

	switch(arithmetic_sing)
	{
		case '+':
			*number = num_1 + num_2;
			break;
		case '-':
			*number = num_1 - num_2;
			break;
		case '*':
			*number = num_1 * num_2;
			break;
		case '/':
			*number = (float)num_1 / num_2;
			break;
	}

	return ptr_equation;
}

void txt_read_text(const char file_with_text[], char str[])
{
	FILE* fp;
	
	if((fp = fopen(file_with_text, "r")) == nullptr)
	{
		cout << "Couldn't open file " << file_with_text << endl;
		exit(1);
	}
	
	fgets(str, AMOUNT_ELEM_STR, fp);	
	cout << "Начальный текст: " << str << endl;

	fclose(fp);
}
