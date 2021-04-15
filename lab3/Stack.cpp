#include "Stack.h"
//#include <iostream>

void menu()
{
	cout << "\n����:";
	cout << "\n   1. ������� �� ����� ���������� � �������.";
	cout << "\n   2. �������� ����� � �������.";
	cout << "\n   3. ������� ����� �� ������ �� ��� ��������.";
	cout << "\n   4. ������� ���� �������.";
	cout << "\n   0. ����� �� ���������.";
	cout << "\n>";
}

void Choice(struct MyStack buff)
{
	int N;
	do{
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
				cout << "\n���������� ������ � �������";
				cout << "\n������� �������� ������: ";
				cin >> name;
				cout << "������� ���� ������: ";
				cin >> cost;
				cout << "������� ��� ������: ";
				cin >> weight;
				cout << "������� ���-�� ������ �� ������: ";
				cin >> value;
				bool check;
				check = buff.Push(name, cost, weight, value);
				if (check)
					cout << "������� ���������.\n";
				else
					cout << "������.\n";
				break;
			}
			
			case 3:
			{
				string popName, name;
				float popCost;
				int popValue, popStoreValue;
				bool check;
				cout << "�������� ������ �� ������� �� ��������.\n������� ��������: ";
				cin >> name;
				buff.SearchPop(name, buff);
				/*if (check)
				{
					cout << "\n�������� �����: " << buff.StackName;
					cout << "\n ��������� �������: " << popName;
					cout << "\n   ��������� ������� cost: " << popCost;
					cout << "\n   ��������� ������� value: " << popValue;
					cout << "\n   ��������� ������� store: " << popStoreValue;
					cout << "\n�������\n";
				}
				else
					cout << "������.\n";*/
				break;
			}

			case 4:
			{
				string popName;
				float popCost;
				int popValue, popStoreValue;
				bool check;
				cout << "������� ���� �������.\n";
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
	cout << "���������� � �����:\n";
	cout << "��� �����: " << StackName << endl;
	if (!Top)
		cout << "\t���� ������\n";
	else
	{
		cout << " ������ ����� = " << Count;
		cout << "\n ���������� � ������� ������: ";
		cout << "\n   ��� = " << Top->name;
		cout << "\n   ���� = " << Top->cost;
		cout << "\n   ��� ������ ������ = " << Top->Value;
		cout << "\n   ���-�� �� ������ = " << Top->storeValue << endl;
	}

}

bool MyStack::SearchPop(string name, struct MyStack &Buff)
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
			cout << "������� ����� �� ������.\n";
			return false;
		}

		//Temp.Info();

		do
		{
			check = Temp.Pop(Name, cost, weight, value);
			if(check == true)
				Buff.Push(Name, cost, weight, value);
		} while (check != false);

		return true;
	}
	
}

bool MyStack::FilePush()
{
	
	struct FilesData{

		string Name;
		float cost;
		int weight, value;
	};

	FilesData Buff;

	ifstream in("file.txt");

	do
	{
		in >> Buff.Name;
		in >> Buff.cost;
		in >> Buff.weight;
		in >> Buff.value;

		Push(Buff.Name, Buff.cost, Buff.weight, Buff.value);
		//Info();

	} while (!in.eof());
	
	in.close();
	return true;
}