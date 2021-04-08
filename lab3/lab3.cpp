//#include <iostream>
#include "func.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    string name = "Тыблоко", popName;
    float cost = 10, popCost;
    int Value = 30, storeValue = 100, popValue, popStoreValue;
    bool check;

    MyStack Apple;
    check = Apple.Push(name, cost, Value, storeValue);
    if(check)
        Apple.Info();
    check = Apple.Pop(popName,popCost,popValue,popStoreValue);
    if (check)
    {
        cout << "\nУдаленный элемент: " << popName;
        cout << "\nУдаленный элемент cost: " << popCost;
        cout << "\nУдаленный элемент value: " << popValue;
        cout << "\nУдаленный элемент store: " << popStoreValue;
    }
        
    return 0;
}

