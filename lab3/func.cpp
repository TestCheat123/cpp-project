#include "func.h"
//#include <iostream>


void menu()
{
	cout << "123" << endl;
}

bool MyStack::Push(string name, float cost, int Value, int storeValue)
{
	if (!Top)
	{
		Top = new Node;
		Top->prev = NULL;
		Count = 1;
	}
	else
	{
		Node* temp;
		temp = new Node;
		temp->prev = Top;
		Top = temp;
		Count++;
	}
	Top->name = name;
	Top->cost = cost;
	Top->Value = Value;
	Top->storeValue = storeValue;
	return true;
}

bool MyStack::Pop(string &name, float &cost, int &value, int &storeValue)
{
	if (!Top) return false;
	Node* temp = Top->prev;
	name = Top->name;
	cost = Top->cost;
	value = Top->Value;
	storeValue = Top->storeValue;
	delete Top;
	Top = temp;
	Count--;
	return true;
}
void MyStack::Info()
{
	cout << "Информация о Стеке:\n";
	if (!Top)
		cout << "\tСтек пустой\n";
	else
	{
		cout << "\tРазмер стека = " << Count;
		cout << "\n\tИнформация о верхнем товаре корзины: ";
		cout << "\n\t\tИмя = " << Top->name;
		cout << "\n\t\tЦена = " << Top->cost;
		cout << "\n\t\tВес одного товара = " << Top->Value;
		cout << "\n\t\tКол-во на складе = " << Top->storeValue << endl;
	}

}

bool MyStack::SearchPop(string name)
{
	if (!Top) return false;
	else
	{
		MyStack Temp;
		string Name;
		float cost;
		int value, storeValue;
		do
		{
			
		} while (Top->name == name);
		return true;
	}
	
}