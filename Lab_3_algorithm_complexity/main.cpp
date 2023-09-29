#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

//Придумать несколько алгоритмов и сравнить их порядок сложности в лучшем, среднем и худшем случаях для решения слудующей задачи.
//Дан массив целых чисел a1, a2, ... , an, заполненный случайно. Необходимо переставить элементы массива так, чтобы вначале в массиве шла группа элементов, больших a1,
//затем сам этот элемент a1, потом группа элементов, меньших или равных ему.
//Комментарий: известно, что данную задачу можно решить таким способом, что число сравнений и перемещений, каждое в отдельности не будет превышать n-1

class Task
{
	int* arNumbers;
	int amountElement;
	int firstElement;

	void RandNumbers();
	public:
	Task()
	{
		do
		{
			cout << "Введите количество элементов в массиве (не более 20): ";
			cin >> amountElement;	
		} while(amountElement <= 0 || amountElement > 20);

		arNumbers = new int[amountElement];
		RandNumbers();
		firstElement = arNumbers[0];
	}
	~Task()
	{
		delete[] arNumbers;
	}
	
	void Print();
	void Algorithm_n();
	void Algorithm_n_squared();
};

void Task::Algorithm_n()
{
	int tmp_ar[amountElement];
	
	int count = 0;
	for (int i = 1; i < amountElement; i++)
	{	
		if(arNumbers[i] >  firstElement)
		{
			tmp_ar[count] = arNumbers[i];
			count++;
		}
	}

	tmp_ar[count] = firstElement;
	count++;

	for (int i = 1; i < amountElement; i++)
	{
		if(arNumbers[i] <= firstElement)
		{
			tmp_ar[count] = arNumbers[i];
			count++;
		}
	}

	for (int i = 0; i < amountElement; i++)
	{
		arNumbers[i] = tmp_ar[i];
	}
}

void Task::Algorithm_n_squared()
{
	for(int i = 0; i < amountElement; i++)
	{
		for(int j = 0; j < amountElement; j++)
		{
			if(arNumbers[j] < arNumbers[j + 1])
			{
				int tmp = arNumbers[j];
				arNumbers[j] = arNumbers[j + 1];
				arNumbers[j + 1] = tmp;				
			}
		}
	}
}

void Task::RandNumbers()
{
	for (int i = 0; i < amountElement; i++)
	{
		arNumbers[i] = rand() % 100 + 1;
	}
}

void Task::Print()
{
	for (int i = 0; i < amountElement; i++)
	{
		cout << "arNumbers[" << i << "] = " << arNumbers[i] << endl; 
	}
}

void Menu(Task& object)
{
	int choise;
	do
	{
		cout << "Каким алгоритмом нужно решить задачу:\n" << "1) Сложность n;\n" << "2) Сложность n^2" << endl;
		cin >> choise;
	} while(choise != 1 && choise != 2);
	
	switch(choise)
	{
	case 1:
		object.Algorithm_n();
		break;
	case 2:
		object.Algorithm_n_squared();
		break;
	}
}

int main()
{
	srand(time(0));
	Task object;
	
	object.Print();

	Menu(object);

	object.Print();

	return 0;
}
