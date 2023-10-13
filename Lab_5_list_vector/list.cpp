#include "list.h"

Queue::Queue(): memory_increment_and_decrement(3), max_amount_element(memory_increment_and_decrement), current_amount_element(0), Arr_element(nullptr)
{
	Arr_element = new Element[max_amount_element];
}

Queue::~Queue()
{
	delete[] Arr_element;
}

void Queue::Push(Element tmp_element)
{
	if (max_amount_element == current_amount_element)
	{
		max_amount_element += memory_increment_and_decrement;
		Element* tmp_arr_element = new Element[max_amount_element];
		for (int i = 0; i < current_amount_element; i++)
		{
			tmp_arr_element[i] = Arr_element[i];
		}
		delete[] Arr_element;
		Arr_element = tmp_arr_element;
		tmp_arr_element = nullptr;
	}

	Arr_element[current_amount_element] = tmp_element;
	current_amount_element++;
}

Element Queue::Pull()
{
	int data_i;
	double data_d;

	if (current_amount_element == 0)
	{
		cout << "Очередь пустая. Невозможно забрать элемент." << endl;
		data_i = 0;
		data_d = 0.0;
	}
	else
	{
		current_amount_element--;
		data_i = Arr_element[0].getData_int();
		data_d = Arr_element[0].getData_double();
		
		for (int i = 0; i < current_amount_element; i++)
		{
			Arr_element[i] = Arr_element[i + 1];
		}

		if (max_amount_element == current_amount_element + memory_increment_and_decrement && current_amount_element != 0)
		{
			max_amount_element -= 5;
			Element* tmp_arr_element = new Element[max_amount_element];
			for (int i = 0; i < current_amount_element; i++)
			{
				tmp_arr_element[i] = Arr_element[i];
			}
			delete[] Arr_element;
			Arr_element = tmp_arr_element;
			tmp_arr_element = nullptr;
		}		
	}
	
	return Element (data_i, data_d);
}

Element* Queue::PullAmountElement(int& amount_element)
{
	Element* QueueElements = nullptr;

	if (IsEmpty())
	{
		cout << "Невозможно переместить " << amount_element << " элементов в другую очередь так как исходная пуста..." << endl;
	}
	else
	{
		char move_quit = 'm';

		if (amount_element > current_amount_element)
		{
			cout << "Число запрошенных элементов превышает количество элементов в очереди. Переместить сколько есть или выйти? (m/q): ";
			cin >> move_quit;
			while (move_quit != 'q' && move_quit != 'm')
			{
				cout << "Введена неверная команда. Воспринимается только \'m\' и \'q\'. Попробуйте снова: ";
				cin >> move_quit;
			}
		}
		
		switch(move_quit)
		{
			case 'm':
				if (amount_element > current_amount_element)
				{
					QueueElements = new Element[current_amount_element];
					amount_element = current_amount_element;
				}
				else
				{
					QueueElements = new Element[amount_element];
				}	
				for (int i = 0; i < amount_element; i++)
				{
					if (current_amount_element != 0)
					{
						QueueElements[i] = Arr_element[i];
						current_amount_element--;
					}
					else break;
				}
				for (int i = 0; i < current_amount_element; i++)
				{
					Arr_element[i] = Arr_element[i + amount_element];
				}
				break;
			case 'q': break; 
		}
	}

	return QueueElements;
}

void Queue::AddElements(Element*& Add_arr_element, int amount_element)
{
	if (Add_arr_element != nullptr)
	{
		for (int i = 0; i < amount_element; i++)
		{
			if (current_amount_element == max_amount_element)
			{
				max_amount_element += memory_increment_and_decrement;
				Element* tmp_arr_element = new Element[max_amount_element];
				for (int i = 0; i < current_amount_element; i++)
				{
					tmp_arr_element[i] = Arr_element[i];
				}
				delete[] Arr_element;
				Arr_element = tmp_arr_element;
				tmp_arr_element = nullptr;

			}
			Arr_element[current_amount_element] = Add_arr_element[i];
			current_amount_element++;
		}

		delete[] Add_arr_element;
		Add_arr_element = nullptr;	
	}
}

void Queue::LookLastElement() const
{
	if (IsEmpty())
	{
		cout << "Нечего показывать так как очередь пустая..." << endl;
	}
	else
	{
		int data_i = Arr_element[0].getData_int();
		double data_d = Arr_element[0].getData_double();
		cout << "Значение последнего элемента:\ndata_int == " << data_i << endl << "data_double == " << data_d << endl;
	}
}

void Queue::DeleteQueue()
{
	delete[] Arr_element;
	Arr_element = nullptr;
	max_amount_element = 0;
	current_amount_element = 0;
}

void Queue::Print() const
{
	if (!IsEmpty())
	{
		for (int i = 0; i < current_amount_element; i++)
		{
			cout << "Element " << i << ": data_int == " << Arr_element[i].getData_int() << "	" << "data_double == " << Arr_element[i].getData_double() << endl;
		}
	}
	else
	{
		cout << "Oчередь пустая..." << endl;
	}
}

int Queue::Size() const
{
	return current_amount_element;
}

bool Queue::IsEmpty() const
{
	bool q_empty;

	if (current_amount_element == 0)
	{
		q_empty = true;
	}
	else
	{
		q_empty = false;
	}
	return q_empty;
}
