#include "menu.h"

int Menu::ChoiceQueue()
{
	int choice;

	cout << "С какой очередью начать работать? (1/2): ";
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		cout << endl << "Принимается только 1 и 2. попробуйте снова: ";
		cin >> choice;
	}
	return choice;
}

bool Menu::SwitchAction(Queue& Que_base, Queue& Que_additionally, int& choice_queue)
{
	bool isRunning = true;
	int choice = ChoiceAction();
	Element e;
	system("clear");

	switch(choice)
	{
		case 1:
			Que_base.Print();
			break;
		case 2:
			if (Que_base.IsEmpty())		cout << "Очередь пустая." << endl;
			else						cout << "Очередь не пустая." << endl;	
			break;
		case 3:
			cout << "Размер очереди в элементах: " << Que_base.Size() << endl;
			break;
		case 4:
			{
				int data_i;
				double data_d;
				cout << endl << "Введите значение поля data_int: ";		cin >> data_i;
				cout << endl << "Введите значение поля data_double: ";	cin >> data_d;
				e.setData_int(data_i);
				e.setData_double(data_d);
				Que_base.Push(e);
				break;
			}
		case 5:
			e = Que_base.Pull();
			cout << "Извлечен элемент с значениями:" << endl << "data_int == " << e.getData_int() << endl << "data_double == " << e.getData_double() << endl;
			break;
		case 6:
			Que_base.LookLastElement();
			break;
		case 7:
			Que_base.DeleteQueue();
			break;
		case 8:
			{
				int amount_element;	
				cout << "Сколько нужно извлечь элементов из очереди и передать в другую: ";
				cin >> amount_element;
				while (amount_element <= 0)
				{
					cout << endl << "Введено неверное количество элементов. Попробуйте снова: ";
					cin >> amount_element;
				}
				Element* arr_e = Que_base.PullAmountElement(amount_element);
				Que_additionally.PushElements(arr_e, amount_element);
				break;
			}
		case 9:
			choice_queue = ChoiceQueue();
			break;
		case 10:
			{
				int amount_element;	
				cout << "Сколько нужно извлечь элементов из очереди и передать в другую: ";
				cin >> amount_element;
				while (amount_element <= 0)
				{
					cout << endl << "Введено неверное количество элементов. Попробуйте снова: ";
					cin >> amount_element;
				}
				Element* arr_e = Que_base.PullAmountElement(amount_element);
				delete[] arr_e;
			}	
			break;
		case 11:
			Que_base.DeleteQueue();
			Que_base.PushRandElements();
			break;
		case 12:
			isRunning = false;
			Que_base.DeleteQueue();
			break;				
	}
	return isRunning;
}

int Menu::ChoiceAction()
{
	int choice = 0;

	do
	{
		cout << " 1) Вывести очередь;" << endl <<
				" 2) Проверить на наличие элементов;" << endl << 
				" 3) Вывести размер очереди в элементах;" << endl <<
				" 4) Поместить элемент в очередь;" << endl <<
				" 5) Извлечь элемент из очереди;" << endl <<
				" 6) Просмотреть первый элемент не извлекая его;" << endl <<
				" 7) Удалить очередь;" << endl <<
				" 8) Переместить n элементов из одной очереди в другую;" << endl <<
				" 9) Переместиться на другую очередь;" << endl << 
				"10) Извлечь n элементов из очереди;" << endl << 
				"11) Заподнить очередь случайными числами;" << endl <<
				"12) Выйти." << endl << endl;
		cout << "Выберите действие которое хотите произвести: ";
		cin >> choice;
	} while (choice < 1 || choice > 12);

	return choice;
}

void Menu::Main()
{
	Queue Que_1, Que_2;
	int choice_queue = 1;
	bool isRunning = true;

	while (isRunning)
	{
		if (choice_queue == 1)
		{
			isRunning = SwitchAction(Que_1, Que_2, choice_queue);
		}
		else
		{
			isRunning = SwitchAction(Que_2, Que_1, choice_queue);
		}
	}
}

