#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int**& a, const int rowcount, const int colcount, int hight, int low);
void Print(int**& a, const int rowcount, const int colcount);
void Change(int**& a, int row1, int row2, int colcount);
void Sort(int**& a, const int rowcount, const int colcount);
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

	Sort(a, rowCount, colCount);
	Print(a, rowCount, colCount);

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

void Change(int**& a, int row1, int row2, int colcount)
{
	int tmp;
	for (int j = 0; j < colcount; j++)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
	}
}

void Sort(int**& a, const int rowcount, const int colcount)
{
	for (int i = 0; i < rowcount - 1; i++)
		for (int i1 = 0; i1 < rowcount - i - 1; i1++)
		{
			if ((a[i1][0] < a[i1 + 1][0])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] < a[i1 + 1][1])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] == a[i1 + 1][1] &&
					a[i1][2] > a[i1 + 1][2]))
				Change(a, i1, i1 + 1, colcount);
		}

}

