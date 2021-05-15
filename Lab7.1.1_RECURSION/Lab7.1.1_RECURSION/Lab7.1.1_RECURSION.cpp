#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int**& a, const int rowcount, const int colcount, int hight, int low, int i, int j);
void Print(int**& a, const int rowcount, const int colcount, int i, int j);
void SumRows(int**& a, const int rowcount, const int colcount, int rowNo, int& S, int& k);
void SumRow(int**& a, const int rowNo, const int colcount, int colNo, int& S, int& k);


int main()
{
	srand(unsigned(time(NULL)));

	int Low;
	int Hight;

	int colCount;
	int rowCount;

	cout << "Min = ";
	cin >> Low;
	cout << "Max = ";
	cin >> Hight;
	cout << "colCount = ";
	cin >> colCount;
	cout << "rowCount = ";
	cin >> rowCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Hight, Low, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	int S = 0;
	int k = 0;

	SumRows(a, rowCount, colCount, 0, S, k);
	cout << endl << "\n";
	Print(a, rowCount, colCount, 0, 0);
	cout << endl << endl << "S = " << S << endl << "k = " << k;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
}

void Create(int**& a, const int rowcount, const int colcount, int hight, int low, int i, int j)
{
	a[i][j] = low + rand() % (hight - low + 1);
	if (j < colcount - 1)
	{
		Create(a, rowcount, colcount, hight, low, i, j + 1);
	}
	else
		if (i < rowcount - 1)
		{
			Create(a, rowcount, colcount, hight, low, i + 1, 0);
		}
}

void Print(int**& a, const int rowcount, const int colcount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colcount - 1)
	{
		Print(a, rowcount, colcount, i, j + 1);
	}
	else
		if (i < rowcount - 1)
		{
			cout << endl;
			Print(a, rowcount, colcount, i + 1, 0);

		}
}

void SumRow(int**& a, const int rowNo, const int colcount, int colNo, int& S, int& k)
{
	if (a[rowNo][colNo] > 0 || !(rowNo % 2 == 0 && colNo % 2 == 0))
	{
		S += a[rowNo][colNo];
		a[rowNo][colNo] = 0;
		k++;
	}
	if (colNo < colcount - 1)
	{
		SumRow(a, rowNo, colcount, colNo + 1, S, k);
	}
}

void SumRows(int**& a, const int rowcount, const int colcount, int rowNo, int& S, int& k)
{
	SumRow(a, rowNo, colcount, 0, S, k);
	if (rowNo < rowcount - 1)
	{
		SumRows(a, rowcount, colcount, rowNo + 1, S, k);
	}
}