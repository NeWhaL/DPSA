#include "menu.h"
#include "list.h"

int Menu::ChoiceAction()
{
	int choice = 0;

	do
	{
		if (choice < 1 || choice > 10)
			system("clear");

		cout << " 1) Вывести очередь;" << endl <<
				" 2) Проверить на наличие элементов;" << endl << 
				" 3) Вывести размер очереди в элементах;" << endl <<
				" 4) Поместить элемент в очередь;" << endl <<
				" 5) Извлечь элемент из очереди;" << endl <<
				" 6) Просмотреть первый элемент не извлекая его;" << endl <<
				" 7) Удалить очередь;" << endl <<
				" 8) Переместить n элементов из одной очереди в другую;" << endl <<
				" 9) Переместиться на другую очередь;" << endl << 
				"10) Извлечь n элементов из очереди;" << endl;
		cout << "Выберите действие которое хотите произвести: ";
		cin >> choice;
	} while (choice < 1 || choice > 10);

	return choice;
}

void Menu::Main()
{
	Queue Que_1, Que_2;

	switch(ChoiceAction())
	{
		case 1:
			cout << "Первая очередь: " << endl;
			Que_1.Print();
			cout << endl << "Вторая очередь: " << endl;
			Que_2.Print();
			break;
		case 2:
			if (Que_1.IsEmpty())
			{
				cout << "Очередь Que_1 не пустая." << endl;
			}
			else
			{
				cout << "Очередь Que_1 пустая." << endl;
			}
			if (Que_2.IsEmpty())
			{
				cout << "Очередь Que_2 не пустая." << endl;
			}
			else
			{
				cout << "Очередь Que_2 пустая." << endl;
			}
			break;
		case 3:
			cout << "Размер очереди Que_1 в элементах: " << Que_1.Size() << endl;
			cout << "Размер очереди Que_2 в элементах: " << Que_2.Size() << endl;
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
	}
}
