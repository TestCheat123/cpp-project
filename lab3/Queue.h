#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Data {
	string name; //Имя группы
	float costbuy, costSell; // Цена покупки, цена продажи
	int Value, Buy, Sold; // Кол-во на складе, куплено, продано
};

struct MyQueue {
	struct Node {
		Data data;
		Node* next;
	};

	Node* First = NULL;
	string QueueName;
	int Count;
	int Profit = 0;


	bool Push(struct Data data);
	bool Pop(struct Data&);
	bool Accept(struct Data data);
	bool Sell(struct Data data);
	
	bool Report();
	void Info();
	void Menu();
	void Choice();
};
