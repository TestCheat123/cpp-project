#include "Queue.h"

void MyQueue::Menu()
{
	cout << "\nМеню работы со складом\n";
	cout << "1. Добавить новый товар\n";
	cout << "2. Докупить товар\n";
	cout << "3. Продать товар\n";
	cout << "4. Составить отчет\n";
	cout << "0. Выход из программы\n";
	cout << ">";
}

void MyQueue::Choice()
{
	int V;
	do
	{
		Menu();
		cin >> V;
		switch (V)
		{
			case 1:
			{
				Data data;
				cout << "Введите название товара: ";
				cin >> data.name;
				cout << "Введите кол-во товара на складе: ";
				cin >> data.Value;
				data.Buy = data.Value;
				cout << "Введите цену закупки товара: ";
				cin >> data.costbuy;
				do
				{
					cout << "Введите цену продажи товара: ";
					cin >> data.costSell;
					if (data.costbuy >= data.costSell)
						cout << "Цена продажи должна быть больше закупочной\nПопробуйте еще раз\n";
				} while (data.costbuy >= data.costSell);
				
				data.Sold = 0;

				Push(data);

				break;
			}

			case 2:
			{
				Data data;
				cout << "Введите название товара, который хотите купить: ";
				cin >> data.name;
				cout << "Введите кол-во покупаемого товара: ";
				cin >> data.Value;
				
				bool check;
				check = Accept(data);
				if (!check)
				{
					cout << "Данный товар не найден на складе, если хотите его добавить на склад, выберите пункт 1 в меню\n";
				}
				break;
			}

			case 3:
			{
				Data data;
				cout << "Введите название товара, который хотите продать: ";
				cin >> data.name;
				cout << "Введите кол-во продаваемого товара: ";
				cin >> data.Value;

				bool check;
				check = Sell(data);
				if (!check)
				{
					cout << "Данный товар не найден на складе, если хотите его добавить на склад, выберите пункт 1 в меню\n";
				}
				break;
			}

			case 4:
			{
				bool check;
				check = Report();
				if (!check) cout << "Товаров на складе нет\n";
				break;
			}

		}
	} while (V != 0);
}

bool MyQueue::Push(struct Data data)
{
	if (!First)
	{
		First = new Node;
		First->next = NULL;
		First->data = data;
		Count = 1;
	}
	else
	{
		Node* temp;
		temp = First;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new Node;
		temp->next->data = data;
		temp->next->next = NULL;
		Count++;
	}
	return true;
}

bool MyQueue::Pop(struct Data &Buff)
{
	if (!First) return false;

	Node* temp = First->next;
	Buff = First->data;
	//cout << Buff.name << endl;
	delete First;
	First = temp;
	Count--;

	return true;
}

bool MyQueue::Accept(struct Data data)
{
	if (!First) return false;
	else
	{
		Data Buff;
		MyQueue Temp;
		bool check = false;
		if (First->data.name == data.name)
		{
			First->data.Value += data.Value;
			First->data.Buy += data.Value;
			return true;
		}
			
		do
		{
			if (check)
				Temp.Push(Buff);
			check = Pop(Buff);
			if (!check) break;

		} while (Buff.name != data.name);

		if (check)
		{
			First->data.Value += data.Value;
			First->data.Sold += data.Value;
			do
			{
				check = Temp.Pop(Buff);
				Push(Buff);
			} while (check != false);
			return true;
		}
		else
		{
			do
			{
				check = Temp.Pop(Buff);
				Push(Buff);
			} while (check != false);
			return false;
		}

	}
	return true;
}

bool MyQueue::Sell(struct Data data)
{
	if (!First) return false;

	Data Buff;
	MyQueue Temp;
	bool check = false;

	if (First->data.name == data.name)
	{
		First->data.Value -= data.Value;
		First->data.Sold += data.Value;
		Profit += data.Value * (First->data.costSell - First->data.costbuy);
		if (First->data.Value == 0)
			Pop(Buff);
		return true;
	}
	
	do
	{
		if (check)
			Temp.Push(Buff);
		check = Pop(Buff);
		if (!check) break;

	} while (Buff.name != data.name);
	
	if (check)
	{
		First->data.Value -= data.Value;
		First->data.Sold += data.Value;
		Profit += data.Value * (First->data.costSell - First->data.costbuy);
		do
		{
			check = Temp.Pop(Buff);
			Push(Buff);
		} while (check != false);
		if (First->data.Value == 0)
			Pop(Buff);
		return true;
	}
	else
	{
		do
		{
			check = Temp.Pop(Buff);
			Push(Buff);
		} while (check != false);
		return false;
	}
	
}

bool MyQueue::Report()
{
	if (!Profit && !First) return false;
	cout << "Отчет:\n";
	if (!First)
	{
		cout << "Кол-во товара на складе: " << 0;
		cout << "\nПрибыль от продажи: " << Profit << endl;
	} 
	else
	{
		int Value = 0, Cost = 0;
		bool check = false;

		MyQueue Temp;
		Data Buff;
		Buff.Value = 0;
		Buff.costbuy = 0;

		Info();

		do
		{
			check = Pop(Buff);
			
			if (check)
			{
				Value += Buff.Value;
				Cost += Buff.Value * Buff.costbuy;
				Temp.Push(Buff);
			}
				

		} while (check != false);

		do
		{
			check = Temp.Pop(Buff);
			Push(Buff);
		} while (check != false);


		
		cout << "Кол-во товара на складе: " << Value;
		cout << "\nСтоимость товара на складе " << Cost;
		cout << "\nПрибыль от продажи: " << Profit << endl;
	}
	
	
	return true;
}

void MyQueue::Info()
{
	cout << "Информация о очереди:\n";
	cout << "\tИмя очереди: " << QueueName << endl;
	if (!First)
	{
		cout << "\tОчередь пустая" << endl;
	}
	else
	{
		cout << "\tКол-во товаров на складе: " << Count << endl;
		cout << "\t\tИнформация о первом в очереди товаре: " << endl;
		cout << "\t\t\tНазвание товара: " << First->data.name << endl;
		cout << "\t\t\tКол-во товара на складе: " << First->data.Value << endl;

	}
}