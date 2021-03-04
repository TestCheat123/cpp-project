#include <iostream>
#include <fstream>

using namespace std;

void Get_n_m(int&, int&);
int GetN();
void NewMatr(int**&, int, int);
void DelMatr(int**&, int, int);
void NewMatr(double**&, int, int);
void DelMatr(double**&, int, int);
void GetMatr(int**, int, int);
void PrintMatr(int**, int, int);
void PrintMatr(double**, int, int);
void GetFileNatr(int**, int, int);
void PrintFileMatr(int**, int, int);
void triangMatr(int**, double**, int);
void Solve(int**, double*, int);
void PrintVect(double*, int);
void findElemet(int**, int);

int main()
{
	setlocale(0, "");
	int n, m;
	Get_n_m(n, m);
	double* x = new double[n];
	int **M1;
	NewMatr(M1, n, m);
	GetMatr(M1, n, m);
	PrintMatr(M1, n, m);
	findElemet(M1, n);
	PrintMatr(M1, n, m);
	Solve(M1, x, n);
	PrintVect(x, n);
	DelMatr(M1, n, m);
	delete[]x; x = NULL;
}

void Get_n_m(int& n, int& m)
{
	cout << "Введите кол-во строк: ";
	n = GetN();
	cout << "Введите кол-во столбцов: ";
	m = GetN();
}
int GetN()
{
	int n;

	do
	{
		cout << "Введите целое число: ";
		cin >> n;
		if (n <= 0 || (n - (int)n))
			cout << "Ошибка, попробуйте снова\n";

	} while (n <= 0 || (n - (int)n));

	return n;
}

void NewMatr(int**& M, int n, int m)
{
	cout << "\tСоздание матрицы...\n";
	M = new int* [n];
	for (int i = 0; i < n; i++)
		M[i] = new int[m];
}
void NewMatr(double**& M, int n, int m)
{
	cout << "\tСоздание матрицы...\n";
	M = new double* [n];
	for (int i = 0; i < n; i++)
		M[i] = new double[m];
}

void DelMatr(int**& M, int n, int m)
{
	cout << "\tУдаление матрицы...\n";
	for (int i = 0; i < n; i++)
		delete[]M[i];
	delete[]M;
}
void DelMatr(double**& M, int n, int m)
{
	cout << "\tУдаление матрицы...\n";
	for (int i = 0; i < n; i++)
		delete[]M[i];
	delete[]M;
}

void GetMatr(int** M, int n, int m)
{
	cout << "Заполните матрицу, размера " << n << " x " << m << " : \n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> M[i][j];
}

void PrintMatr(int** M, int n, int m)
{
	cout << "\tМатрица:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << "\t" << M[i][j];
		cout << endl;
	}
	cout << endl;
}
void PrintMatr(double** M, int n, int m)
{
	cout << "\tМатрица:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << "\t" << M[i][j];
		cout << endl;
	}
	cout << endl;
}
void PrintVect(double* x, int n)
{
	cout << "\tВектор:\n";
	for (int i = 0; i < n; i++)
		cout << "\t" << x[i];
}

void GetFileNatr(int** M, int n, int m) 
{
	fstream f_in("matr.txt", ios::in);
	if (f_in)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if (!f_in >> M[i][j])
				{
					cout << "Ошибка, файловый поток не был открыт\n";
					break;
					f_in.close();
				}
		f_in.close();
	}
	else cout << "Ошибка, файловый поток не был открыт\n";

}
void PrintFileMatr(int** M, int n, int m)
{
	fstream f_out("output.txt", ios::out);
	if (f_out)
	{
		for (int i = 0; i < n; i++) 
		{
			for(int j = 0; j < m; j++)
				f_out << "\t" << M[i][j];
			f_out << endl;
		}
		f_out.close();
	}
	else cout << "Ошибка, файловый поток не был открыт";
}

void findElemet(int** M, int n)
{
	int temp = 0, max = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (max < M[i][j])
			{
				max = M[i][j];
				temp = i;
			}
		}
		M[temp][j] = M[j][j];
		
		M[j][j] = max;
		max = 0;
	}
}

void triangMatr(int** A, double** B, int n)
{
	double koef;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n+1; j++)
			B[i][j] = A[i][j];

	for(int k = 0; k < n; k++)
		for (int i = k + 1; i < n; i++)
		{
			koef = -1. * B[i][k] / B[k][k];
			for (int j = k; j < n + 1; j++)
				B[i][j] = B[i][j] + B[k][j] * koef;
		}
	PrintMatr(B, n, n + 1);
}
void Solve(int** A, double* x, int n)
{
	double res = 0;
	double** B;
	NewMatr(B, n, n + 1);
	triangMatr(A, B, n);
	for (int i = n - 1; i >= 0; i--)
	{
		res = 0;
		for (int j = i + 1; j <= n - 1; j++)
			res = res - x[j] * B[i][j];

		res += B[i][n];
		x[i] = res / B[i][i];
	}
	DelMatr(B, n, n + 1);
}
