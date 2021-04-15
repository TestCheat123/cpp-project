#include "Stack.h"
#include "Queue.h"
#define LC_ALL 0

void Task()
{
    cout << "Выберите задание:\n"
        << "1. Работа с корзиной через Стек.\n"
        << "2. Работа со складом через Очередь\n"
        << ">";
}

int main()
{
    //setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    MyQueue Store;
    Store.QueueName = "склад";
    Data data;
    data.name = "123";
    data.costbuy = 100;
    data.Value = 10;

    Store.Choice();
    //Store.Pop(data);
    Store.Info();

   /* int N;
    menu();
    cin >> N;
    switch (N)
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
            break;
        }
    }
    */
    

    return 0;
}

