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

	Node* Top = NULL;
	int Count;
	bool Push(string,float,int,int);
	bool Pop(string&,float&,int&,int&);
	bool SearchPop(string);
	void Info();
};

void menu();
