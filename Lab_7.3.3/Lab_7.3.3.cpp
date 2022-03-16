#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Input(int** a, const int rowCount, const int colCount, int rowNo);
void Input2(int** a, const int rowNo, const int colCount, int colNo);
void Show(int** a, const int rowCount, const int colCount, int rowNo);
void Show2(int** a, const int rowNo, const int colCount, int colNo);
int Sum(int** a, int colNo, int rowNo, const int rowCount, const int colCount, bool& minus_element, int& S);
void Sum2(int** a, const int rowCount, int colNo, int rowNo, bool& minus_element);
void Sum3(int** a, const int colCount, int colNo, int rowNo, bool& minus_element, int& S);


int main()
{
	int rowCount, colCount, s = 0;
	bool minus_element = false,are=true;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Input(a, rowCount, colCount,0);
	Show(a, rowCount, colCount,0);
	cout << "S = " << Sum(a, 0, 0, rowCount, colCount, minus_element, s) << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}



void Input(int** a, const int rowCount, const int colCount, int rowNo)
{
	Input2(a, rowNo, colCount, 0);
	if (rowNo<rowCount-1)
	{
		Input(a, rowCount, colCount, rowNo + 1);
	}
	else
	{
		cout << endl;
	}
}

void Input2(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
	{
		Input2(a, rowNo, colCount, colNo + 1);
	}
	else
	{
		cout << endl;
	}
}

void Show(int** a, const int rowCount, const int colCount, int rowNo)
{
	Show2(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
	{
		Show(a, rowCount, colCount, rowNo + 1);
	}
	else
	{
		cout << endl;
	}

}

void Show2(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
	{
		Show2(a, rowNo, colCount, colNo + 1);
	}
	else
	{
		cout << endl;
	}
}



int Sum(int** a, int colNo, int rowNo, const int rowCount, const int colCount, bool& minus_element,int & S)
{
	int s = 0;
	minus_element = false;
	Sum2(a, rowCount, colNo, rowNo, minus_element);
	if (!minus_element)
	{
		Sum3(a, rowCount, colNo, rowNo, minus_element, S);
	}
	if (colNo < colCount - 1)
	{
		Sum(a, colNo + 1, rowNo, rowCount, colCount, minus_element,S);
	}
	else
	{
		s = S;
		return s;
	}
}



void Sum2(int** a, const int rowCount,  int colNo,int rowNo, bool& minus_element)
{
	if (a[rowNo][colNo] < 0)
	{
		minus_element = true;
		return;
	}
	if (rowNo<rowCount-1)
	{
		Sum2(a, rowCount,  colNo, rowNo + 1, minus_element);
	}
}


void Sum3(int** a, const int colCount, int colNo,int rowNo, bool& minus_element, int& S)
{
	S += a[rowNo][colNo];
	if (rowNo<colCount-1)
	{
		Sum3(a, colCount, colNo, rowNo+1, minus_element, S);
	}
}