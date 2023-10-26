#include "list.h"

List::List(): head(nullptr), tail(nullptr) {};

List::List(int amount_elements): head(nullptr), tail(nullptr)
{
	if (amount_elements > 0)
	{
		for (int i = 0; i < amount_elements; i++)
		{
			int data = rand() % 100 + 1;
			Push(data);
		}
	}
	else
	{
		cout << "Количество элементов в списке не может быть меньше или равно 0..." << endl;
	}
}

void List::Push(int data)
{
	Element* e = new Element;
	e->data = data;
	e->next = nullptr;

	if (head == nullptr)
	{
		head = e;
		tail = e;
	}
	else if (head == tail)
	{
		tail->next = e;
		head->next = e;
		tail = e;
	}
	else
	{
		tail->next = e;
		tail = e;
	}
}

void List::PushHead(int data)
{
	Element* e = new Element;
	e->data = data;
	e->next = nullptr;

	if (head == nullptr)
	{
		head = e;
		tail = e;
	}
	else
	{
		e->next = head;
		head = e;
	}
}

void List::Print() const
{
	if (head != nullptr)
	{
		for (Element* e = head; e != nullptr; e = e->next)
		{
			cout << e->data << " -> ";
		}
		cout << endl;
	}
	else
	{
		cout << "Нечего выводить на экран так как список пустой..." << endl;
	}
}

void List::Delete()
{
	for (Element* e = head; e != nullptr; e = head)
	{
		head = head->next;
		delete e;
	}
}

void List::Sort()
{
	for (Element* noname = head; noname != nullptr; noname = noname->next)
	{
		for (Element* e = head; e != nullptr; e = e->next)
		{
			if (e->next != nullptr)
			{
				if (e->data > e->next->data)
				{
					int tmp = e->data;
					e->data = e->next->data;
					e->next->data = tmp;
				}
			}
		}
	}
}
