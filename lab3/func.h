#pragma once

#include <iostream>
#include <string>

using namespace std;

struct MyStack {
	struct Node
	{		
		string name;
		float cost;
		int Value, storeValue;
		Node* prev;
	};

	string StackName;
	Node* Top = NULL;
	int Count = 0;
	bool Push(string,float,int,int);
	bool Pop(string&,float&,int&,int&);
	bool SearchPop(string, struct MyStack &Buff);
	void Info();
};

struct MyQueue {
	struct Node {
		string name;
		int value;
		float cost; 
	};

	string QueueName;

	bool Push(string, float, int, int);
	bool Pop(string&, float&, int&, int&);
	void Info();
};

void menu();
void Choice(struct MyStack buff);
