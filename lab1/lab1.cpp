#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int max_rand = 10;

void arr_read(int*, int);
void arr_ins(int);
void arr_print(int*, int);
void push_back_arr(int*&, int&);
void push_front_arr(int*&, int&);
void delete_back_arr(int*&, int&);
void delete_front_arr(int*&, int&);
void push_k_arr(int*&, int&);
void delete_k_arr(int*&, int&);
void push_value_arr(int*&, int&); 
void delete_value_arr(int*&, int&);

int main()
{
    //srand(time(NULL));
    int size_arr;
    setlocale(0, "");
    cout << "" << endl;
    cin >> size_arr;
    int* arr = new int[size_arr];
    arr_ins(size_arr);
    arr_read(arr, size_arr);
    arr_print(arr, size_arr);
    cout << endl;
    delete_value_arr(arr, size_arr);
    arr_print(arr, size_arr);
    return 0;
}

void arr_ins(int n) {
    fstream f_out("arr.txt", ios::out);
    for (int i = 0; i < n; i++) {
        f_out << rand() % max_rand << " ";
    }
    f_out.close();
}

void arr_read(int* arr, int n) {
    fstream f_in("arr.txt", ios::in);
    if (f_in) {
        for (int i = 0; i < n; i++) {
            f_in >> arr[i];
        }
        f_in.close();
    }
}

void arr_print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "]: " << arr[i] << "\t" << arr + i << endl;
    }

}

void push_back_arr(int *&arr, int &n) {
    int k;
    cout << "Сколько элементов массива добавить в конец массива: ";
    cin >> k;
    int* newArray = new int[n + k];
    for (int i = 0; i < n; i++)
    {
        newArray[i] = arr[i];
    }
    cout << "Введите добавляемые элементы, " << k << " штук: " << endl;
    for (int i = n; i < (n + k); i++)
    {
        cin >> newArray[i];
    }
    delete[]arr;
    arr = newArray;
    n += k;
}
void push_front_arr(int*& arr, int& n)
{
    int k;
    cout << "Сколько элементов массива добавить в начало массива: ";
    cin >> k;
    int* newArray = new int[n + k];
    for (int i = 0; i < n; i++)
    {
        newArray[i+k] = arr[i];
    }
    cout << "Введите добавляемые элементы, " << k << " штук: " << endl;
    for (int i = 0; i < k; i++)
    {
        cin >> newArray[i];
    }
    delete[]arr;
    arr = newArray;
    n += k;
}

void delete_back_arr(int*& arr, int& n)
{
    int k;
    cout << "Сколько элементов массива удалить в конце массива: ";
    cin >> k;
    int* newArray = new int[n - k];
    for (int i = 0; i < (n - k); i++)
    {
        newArray[i] = arr[i];
    }
    delete[]arr;
    arr = newArray;
    n -= k;

}


void delete_front_arr(int*& arr, int& n)
{
    int k;
    cout << "Сколько элементов массива удалить в начале массива: ";
    cin >> k;
    int* newArray = new int[n - k];
    for (int i = 0; i < (n - k); i++)
    {
        newArray[i] = arr[i+k];
    }
    delete[]arr;
    arr = newArray;
    n -= k;

}

void push_k_arr(int*& arr, int& n)
{
    int k;
    cout << "На какое место (всего мест " << n << ") массива добавить элемент: ";
    cin >> k;
    int* newArray = new int[n + 1];
    for (int i = 0; i < k; i++)
    {
        newArray[i] = arr[i];
    }
    cout << "Введите добавляемый элемент: ";
    cin >> newArray[k - 1];
    for (int i = k; i <(n + 1); i++)
    {
        newArray[i] = arr[i-1];
    }
    delete[]arr;
    arr = newArray;
    n++;
}

void delete_k_arr(int*& arr, int& n)
{
    int k;
    cout << "Какой элемент (всего элементов " << n << " штук) массива удалить (введите номер от 1, до " << n << "): ";
    cin >> k;
    int* newArray = new int[n - 1];
    for (int i = 0; i < k; i++)
    {
        newArray[i] = arr[i];
    }
    for (int i = (k - 1); i < (n - 1); i++)
    {
        newArray[i] = arr[i + 1];
    }
    delete[]arr;
    arr = newArray;
    n--;
}

void push_value_arr(int*& arr, int& n)
{
    int k, result = 0, buf;
    cout << "После какого какого встреченного в массиве значения добавить элемент: ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k) { result = 1; buf = i; break; }
    }
    if (result == 1) {
        int* newArray = new int[n + 1];
        for (int i = 0; i < (buf + 1); i++)
        {
            newArray[i] = arr[i];
        }
        cout << "Введите добавляемый элемент: ";
        cin >> newArray[buf + 1];
        for (int i = buf + 2; i < (n + 1); i++)
        {
            newArray[i] = arr[i - 1];
        }
        delete[]arr;
        arr = newArray;
        n++;
    }
    else
    {
        cout << "Произошла ошибка (Элемент с таким значением не найден)" << endl;
    }

}

void delete_value_arr(int*& arr, int& n)
{
    int k, result = 0, buf = 0, buf2 = 0;
    cout << "Элементы с каким значением удалить: ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == k) { result = 1; buf++; }
    }
    if (result == 1)
    {
        int* newArray = new int[n - buf];
        for (int i = 0; i < n; i++)
        {
            if(arr[i] != k) 
            {
                newArray[i - buf2] = arr[i];
            }
            else
            {
                buf2++;
                continue;
            }
        }
        delete[]arr;
        arr = newArray;
        n -= buf;
    }
    else
    {
        cout << "Произошла ошибка (Элемент с таким значением не найден)" << endl;
    }
}