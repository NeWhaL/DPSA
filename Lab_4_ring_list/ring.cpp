#include "ring.h"

void ring::PushNext(double data)
{
	element* elm = new element;
	elm->data = data;
	if(head == nullptr)
	{
		head = elm;
		head->next = head;
		head->prev = head;
		amountElement++;
	}
	else
	{
		elm->prev = head;
		elm->next = head->next;
		head->next->prev = elm;
		head->next = elm;
		amountElement++;
	}
}

void ring::PushPrev(double data)
{
	element* elm = new element;
	elm->data = data;
	if(head == nullptr)
	{
		head = elm;
		head->next = head;
		head->prev = head;
		amountElement++;
	}
	else
	{
		elm->prev = head->prev;
		elm->next = head;
		head->prev->next = elm;
		head->prev = elm;
		amountElement++;
	}
}

void ring::GoNext()
{
	if (head == nullptr) 
	{
		cout << "Список пуст.\n";
		return;
	}
	head = head->next;
}

void ring::GoPrev()
{
	if (head == nullptr) 
	{
		cout << "Список пуст.\n";
		return;
	}
	head = head->prev;
}

void ring::SearchElement(double data) const
{
	bool element_exists;
	element* elem = nullptr;
	
	if (head != nullptr)
	{
		for (elem = head; elem != head->prev; elem = elem->next)
		{
			if (data == elem->data)
			{
				element_exists = true;
				cout << "Элемент с значением " << data << " существует" << endl;
				break;
			}
			else element_exists = false;
		}

		if (!element_exists)
		{
			if (data == elem->data)
			{
				element_exists = true;
				cout << "Элемент с значением " << data << " существует" << endl;
			}
			else element_exists = false;

		}

		if (!element_exists)
		{
			cout << "Элемента с значением " << data << " не присутвтвует в кольцевом списке" << endl;
		}
	}
	else
	{
		cout << "Список пуст..." << endl;
	}
}

void ring::DeleteElement()
{
	if (head == nullptr)
	{
		cout << "Список пуст." << endl;
	}
	else if (head->next == head->prev)
	{
		delete head;
		head = nullptr;
		amountElement--;
	}
	else
	{
		element* tmp = head;
		head->next->prev = head->prev;
		head->prev->next = head->next;
		head = head->next;
		delete tmp;
		amountElement--;
	}
}

void ring::DeleteElement(int index)
{
	for (int i = 0; i < index; i++)
	{
		GoNext();
	}
	DeleteElement();
	for (int i = 0; i < index; i++)
	{
		GoPrev();
	}
}

void ring::DeleteList()
{
	while (head != nullptr)
	{
		DeleteElement();
	}
}

void ring::DeleteData(double data)
{
	element* tmp;
	int count = 0;
	for (tmp = head; tmp != head->prev; tmp = tmp->next)
	{
		if (tmp->data == data)
		{
			DeleteElement(count);
			break;
		}
		count++;
	}
	if (tmp->data == data)
	{
		DeleteElement(count);
	}
	else
	{
		cout << "Элеметнта с таким значением как: " << data << " не существует." << endl;
	}
}

void ring::Print()
{
	if (head != nullptr)
	{
		cout << "<->";
		for (element* tmp = head; tmp != head->prev; tmp = tmp->next)
		{
			cout << tmp->data << "<->";
		}
		cout << head->prev->data;
	}
	else
	{
		cout << "Список пуст.";
	}
	cout << endl;
}
