#include "func.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
 
    MyStack Pie;
    Pie.StackName = "Пирожки Крутые";
    Choice(Pie);

    return 0;
}

