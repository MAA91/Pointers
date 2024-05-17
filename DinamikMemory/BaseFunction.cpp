//BaseFunction.cpp
#include "BaseFunction.h"

template <typename T> void Print(T A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << "\t";
	cout << endl;
}
template <typename T> void Print(T** A, int ROW, int COL)
{
	for (int i = 0; i < ROW; i++) Print(A[i], COL);
}

template <typename T> void Search(T A[])
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
				cout << "������� " << A[i] << " ���������� " << col << " ���\n";
		}
	}
}