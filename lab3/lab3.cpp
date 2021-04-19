#include "Stack.h"
#include "Queue.h"
#include <windows.h>
#define LC_ALL 0

void Task()
{
    cout << "Выберите задание:\n"
        << "1. Работа с корзиной через Стек.\n"
        << "2. Работа со складом через Очередь\n"
        << "0. Выход\n"
        << ">";
}

int main()
{
    //setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    int n;
    do {
        Task();
        cin >> n;
        switch (n)
        {
        case 1:
        {
            MyStack Pie;
            Pie.StackName = "Пирожки Крутые";
            Pie.FilePush();
            Choice(Pie);
            break;
        }

        case 2:
        {
            MyQueue Store;
            Store.QueueName = "склад";
            Data data;
            data.name = "123";
            data.costbuy = 100;
            data.Value = 10;

            Store.Choice();
            //Store.Pop(data);
            Store.Info();

            break;
        }
        }
    } while (n != 0);
   



    return 0;
}
