#include "Stack.h"
//#include <iostream>

void menu()
{
	cout << "\nМеню:";
	cout << "\n   1. Вывести на экран информацию о коризне.";
	cout << "\n   2. Добавить товар в корзину.";
	cout << "\n   3. Удалить товар из корзин по его названию.";
	cout << "\n   4. Очистка всей корзины.";
	cout << "\n   0. Выход из программы.";
	cout << "\n>";
}

void Choice(struct MyStack buff)
{
	int N;
	do {
		menu();
		cin >> N;
		switch (N)
		{
		case 1:
			buff.Info();
			break;

		case 2:
		{
			string name;
			float cost;
			int weight, value;
			cout << "\nДобавление товара в корзину";
			cout << "\nВведите название товара: ";
			cin >> name;
			cout << "Введите цену товара: ";
			cin >> cost;
			cout << "Введите вес товара: ";
			cin >> weight;
			cout << "Введите кол-во товара на складе: ";
			cin >> value;
			bool check;
			check = buff.Push(name, cost, weight, value);
			if (check)
				cout << "Успешно завершено.\n";
			else
				cout << "Ошибка.\n";
			break;
		}

		case 3:
		{
			string popName, name;
			float popCost;
			int popValue, popStoreValue;
			bool check;
			cout << "Удаление товара из корзины по названию.\nВведите название: ";
			cin >> name;
			buff.SearchPop(name, buff);
			/*if (check)
			{
			cout << "\nНазвание стека: " << buff.StackName;
			cout << "\n Удаленный элемент: " << popName;
			cout << "\n   Удаленный элемент cost: " << popCost;
			cout << "\n   Удаленный элемент value: " << popValue;
			cout << "\n   Удаленный элемент store: " << popStoreValue;
			cout << "\nУспешно\n";
			}
			else
			cout << "Ошибка.\n";*/
			break;
		}

		case 4:
		{
			string popName;
			float popCost;
			int popValue, popStoreValue;
			bool check;
			cout << "Очистка всей корзины.\n";
			do {
				check = buff.Pop(popName, popCost, popValue, popStoreValue);
			} while (check != false);
			break;
		}
		}
	} while (N != 0);
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

bool MyStack::Pop(string& name, float& cost, int& value, int& storeValue)
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
	cout << "Имя стека: " << StackName << endl;
	if (!Top)
		cout << "\tСтек пустой\n";
	else
	{
		cout << " Размер стека = " << Count;
		cout << "\n Информация о верхнем товаре: ";
		cout << "\n   Имя = " << Top->name;
		cout << "\n   Цена = " << Top->cost;
		cout << "\n   Вес одного товара = " << Top->Value;
		cout << "\n   Кол-во товара в магазине = " << Top->storeValue << endl;
	}

}

bool MyStack::SearchPop(string name, struct MyStack& Buff)
{
	if (!Top) return false;
	else
	{
		MyStack Temp;
		string Name, tempName;
		float cost;
		int weight, value;
		bool check = false;
		do
		{
			if (check == true)
				Temp.Push(Name, cost, weight, value);
			check = Buff.Pop(Name, cost, weight, value);
			if (check != true)
				break;

		} while (Name != name);

		if (check == false)
		{
			cout << "Искомый товар не найден.\n";
			return false;
		}

		//Temp.Info();

		do
		{
			check = Temp.Pop(Name, cost, weight, value);
			if (check == true)
				Buff.Push(Name, cost, weight, value);
		} while (check != false);

		return true;
	}

}

bool MyStack::FilePush()
{

	struct FilesData {

		string Name;
		float cost;
		int weight, value;
	};

	FilesData Buff;

	ifstream in("file.txt");

	while (in >> Buff.Name >> Buff.cost >> Buff.weight >> Buff.value)
	{
		Push(Buff.Name, Buff.cost, Buff.weight, Buff.value);
	}
	//Info();

	in.close();
	return true;
}
