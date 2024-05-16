//BaseFunction.cpp
#include "BaseFunction.h"

template <typename T>
void Print(T A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}
template <typename T>
void Print(T** A, int ROW, int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
}

template <typename T>
void Search(T A[])
{
	T BUF[SIZE]{};
	int size_BUF{};
	for (int i = 0; i < SIZE; i++)
	{
		bool flag = true;
		for (int j = 0; j < size_BUF; j++)
			if (A[i] == BUF[j])
			{
				flag = false;
				break;
			}
		if (flag)
		{
			BUF[size_BUF++] = A[i];
			int col{};
			for (int j = i; j < SIZE; j++)
				if (A[i] == A[j])
					col++;
			if (col != 1)
				cout << "Ёлемент " << A[i] << " повторилс€ " << col << " раз\n";
		}
	}
}