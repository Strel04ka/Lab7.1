#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int**& a, const int rowcount, const int colcount, int hight, int low);
void Print(int**& a, const int rowcount, const int colcount);
void Calc(int**& a, const int rowcount, const int colcount, int& S, int& k);


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

	Create(a, rowCount, colCount, Hight, Low);
	Print(a, rowCount, colCount);

	int S = 0;
	int k = 0;

	Calc(a, rowCount, colCount, S, k);
	Print(a, rowCount, colCount);
	cout << endl << endl << "S = " << S << endl << "k = " << k;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
}

void Create(int**& a, const int rowcount, const int colcount, int hight, int low)
{
	for (int i = 0; i < rowcount; i++)
		for (int j = 0; j < colcount; j++)
			a[i][j] = low + rand() % (hight - low + 1);
}

void Print(int**& a, const int rowcount, const int colcount)
{
	cout << endl << endl;
	for (int i = 0; i < rowcount; i++)
	{
		for (int j = 0; j < colcount; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
}

void Calc(int**& a, const int rowcount, const int colcount, int& S, int& k)
{
	for (int i = 0; i < rowcount; i++)
		for (int j = 0; j < colcount; j++)
		{
			if (a[i][j] > 0 || !(i % 2 == 0 && j % 2 == 0))
			{
				S += a[i][j];
				a[i][j] = 0;
				k++;
			}
		}
}
