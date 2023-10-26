/*Связи в связанном списке содержат ключевое поле типа
integer. Напишите программу сортировки списка в порядке
возрастания значения ключей. Затем сформулируйте процедуру,
формирующую список, в котором элементы расположены в обратном
порядке.*/
#include "list.h"


int main()
{
	srand(time(NULL));
	
	int amount_elements = AmountElementInList();
	List list_1(amount_elements);
	List list_2;

	list_1.Print();
	list_1.Sort();
	list_1.Print();
	
	NewList(list_1, list_2, amount_elements);
	cout << "Лист 1: " << endl;
	list_1.Print();
	cout << "Лист 2: " << endl;
	list_2.Print(); 

	return 0;
}

void NewList(const List& list_base, List& list_new, int amount_elements)
{
	for (List::Element* e = list_base.head; e != nullptr; e = e->next)
	{
		list_new.PushHead(e->data);
	}
}

int AmountElementInList()
{
	int amount_elements;

	cout << "Введите количество элементов в списке: ";
	cin >> amount_elements;
	while (amount_elements <= 0)
	{
		cout << "Элементов не может быть меньше или равно 0. Попробуйте снова: ";
		cin >> amount_elements;
	}
	return amount_elements;
}
