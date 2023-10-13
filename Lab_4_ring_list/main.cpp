#include "ring.h"

void Menu(ring&);
double Data();
int Index();

int main()
{
	system("clear");
	ring ringObject;
	Menu(ringObject);
	return 0;
}

void Menu(ring& ringObject)
{
	int choise = 2;

	while(choise >= 2 && choise <= 11)
	{
		cout << "Введите номер действия: " << endl << 
					"1) Выйти;\n" << 
					"2) Вывод списка на экран;\n" << 
					"3) Добавить элемент ДО головы;\n" <<
					"4) Добавить элемент ПЕРЕД головой;\n" <<
					"5) Переместить курсор вперед;\n" << 
					"6) Переместить курсор назад;\n" << 
					"7) Удалить текущий элемент;\n" <<
					"8) Удалить элемент по индексу;\n" << 
					"9) Удалить весь список;\n" <<
					"10) Удалить элемент по его значению;\n" <<
					"11) Искать элемент по значению.\n"; 
		do
		{
			if (choise < 1 || choise > 11)
			{
				cout << endl << "Неверный номер пункта. Попробуйте снова: ";
			}
			cin >> choise;
		} while(choise < 1 || choise > 11);

		switch(choise)
		{
			case 1:
				break;
			case 2:
				ringObject.Print();
				break;
			case 3:
				ringObject.PushPrev(Data());
				ringObject.Print();
				break;
			case 4:
				ringObject.PushNext(Data());
				ringObject.Print();
				break;
			case 5:
				ringObject.GoNext();
				ringObject.Print();
				break;
			case 6:
				ringObject.GoPrev();
				ringObject.Print();
				break;
			case 7:
				ringObject.DeleteElement();
				ringObject.Print();
				break;
			case 8:				
				ringObject.DeleteElement(Index());
				ringObject.Print();
				break;
			case 9:
				ringObject.DeleteList();
				break;
			case 10:
				ringObject.DeleteData(Data());
				ringObject.Print();
				break;
			case 11:	
				double data;
				cout << "Введите элемент который нужно найти: ";
				cin >> data;
				ringObject.SearchElement(data);
				break;
		}
	}
}

double Data()
{
	double data;
	cout << "Введите данные: ";
	cin >> data;
	return data;
}

int Index()
{
	int index;
	do
	{
		cout << "Введите индекс элемента, который надо удалить: ";
		cin >> index;	
	} while(index <= 0);	
	return index;
}
