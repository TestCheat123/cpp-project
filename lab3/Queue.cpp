#include "Queue.h"

void MyQueue::Menu()
{
	cout << "\n���� ������ �� �������\n";
	cout << "1. �������� ����� �����\n";
	cout << "2. �������� �����\n";
	cout << "3. ������� �����\n";
	cout << "4. ��������� �����\n";
	cout << "0. ����� �� ���������\n";
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
				cout << "������� �������� ������: ";
				cin >> data.name;
				cout << "������� ���-�� ������ �� ������: ";
				cin >> data.Value;
				data.Buy = data.Value;
				cout << "������� ���� ������� ������: ";
				cin >> data.costbuy;
				do
				{
					cout << "������� ���� ������� ������: ";
					cin >> data.costSell;
					if (data.costbuy >= data.costSell)
						cout << "���� ������� ������ ���� ������ ����������\n���������� ��� ���\n";
				} while (data.costbuy >= data.costSell);
				
				data.Sold = 0;

				Push(data);

				break;
			}

			case 2:
			{
				Data data;
				cout << "������� �������� ������, ������� ������ ������: ";
				cin >> data.name;
				cout << "������� ���-�� ����������� ������: ";
				cin >> data.Value;
				
				bool check;
				check = Accept(data);
				if (!check)
				{
					cout << "������ ����� �� ������ �� ������, ���� ������ ��� �������� �� �����, �������� ����� 1 � ����\n";
				}
				break;
			}

			case 3:
			{
				Data data;
				cout << "������� �������� ������, ������� ������ �������: ";
				cin >> data.name;
				cout << "������� ���-�� ������������ ������: ";
				cin >> data.Value;

				bool check;
				check = Sell(data);
				if (!check)
				{
					cout << "������ ����� �� ������ �� ������, ���� ������ ��� �������� �� �����, �������� ����� 1 � ����\n";
				}
				break;
			}

			case 4:
			{
				bool check;
				check = Report();
				if (!check) cout << "������� �� ������ ���\n";
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
	cout << "�����:\n";
	if (!First)
	{
		cout << "���-�� ������ �� ������: " << 0;
		cout << "\n������� �� �������: " << Profit << endl;
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


		
		cout << "���-�� ������ �� ������: " << Value;
		cout << "\n��������� ������ �� ������ " << Cost;
		cout << "\n������� �� �������: " << Profit << endl;
	}
	
	
	return true;
}

void MyQueue::Info()
{
	cout << "���������� � �������:\n";
	cout << "\t��� �������: " << QueueName << endl;
	if (!First)
	{
		cout << "\t������� ������" << endl;
	}
	else
	{
		cout << "\t���-�� ������� �� ������: " << Count << endl;
		cout << "\t\t���������� � ������ � ������� ������: " << endl;
		cout << "\t\t\t�������� ������: " << First->data.name << endl;
		cout << "\t\t\t���-�� ������ �� ������: " << First->data.Value << endl;

	}
}