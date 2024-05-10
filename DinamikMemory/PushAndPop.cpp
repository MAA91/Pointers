//PushAndPop.cpp
#include "PushAndPop.h"

int* PushBack(int* A, int& size_A, int element)
{
	int* Buf = new int[size_A + 1];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = *(A + i);
	*(Buf + size_A) = element;
	size_A++;
	delete[] A;
	return Buf;
}
int* PushFront(int* A, int& size_A, int element)

{
	int* Buf = new int[++size_A];
	*Buf = element;
	for (int i = 1; i < size_A; i++)
		*(Buf + i) = *(A + i - 1);
	delete[] A;
	return Buf;
}

int* PopBack(int* A, int& size_A)
{
	int* Buf = new int[--size_A];
	for (int i = 0; i < size_A; i++) *(Buf + i) = *(A + i);
	delete[] A;
	return Buf;
}
int* PopFront(int* A, int& size_A)
{
	int* Buf = new int[--size_A];
	for (int i = 0; i < size_A; i++) *(Buf + i) = *(A + i + 1);
	delete[] A;
	return Buf;
}

int* Insert(int* A, int& size_A, int element, int index)
{
	int* Buf = new int[++size_A];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = (i < index ? *(A + i) :
			(i > index ? *(A + i - 1) : element));
	delete[] A;
	return Buf;
}
int* Erase(int* A, int& size_A, int index)
{
	int* Buf = new int[size_A - 1];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = (i < index ? *(A + i) : *(A + i + 1));
	size_A--;
	delete[] A;
	return Buf;
}

int** Allocate(int rows_A, int cols_A)
{
	int** A = new int* [rows_A];
	for (int i = 0; i < rows_A; i++)
		A[i] = new int[cols_A];
	return A;
}
void Clear(int** A, int rows_A)
{
	for (int i = 0; i < rows_A; i++)
		delete[] A[i];
	delete[] A;
}

int** PushRowBack(int** A, int& rows_A, int cols_A, int* B)
{
	int** Buf = new int* [++rows_A];
	Buf[rows_A - 1] = new int[cols_A];
	for (int i = 0; i < rows_A - 1; i++)
		Buf[i] = A[i];
	for (int j = 0; j < cols_A; j++)
		Buf[rows_A - 1][j] = B[j];
	delete[] A;
	return Buf;
}
int** PushRowFront(int** A, int& rows_A, int cols_A, int* B)
{
	int** Buf = new int* [++rows_A];
	Buf[0] = new int[cols_A];
	for (int j = 0; j < cols_A; j++)
		Buf[0][j] = B[j];
	for (int i = 1; i < rows_A; i++)
		Buf[i] = A[i - 1];
	delete[] A;
	return Buf;
}
int** InsertRow(int** A, int& rows_A, int cols_A, int* B, int index_Row)
{
	int** Buf = new int* [++rows_A];
	Buf[index_Row] = new int[cols_A];
	for (int j = 0; j < cols_A; j++)
		Buf[index_Row][j] = B[j];
	for (int i = 0; i < rows_A; i++)
		if (i != index_Row)
			Buf[i] = (i < index_Row ? A[i] : A[i - 1]);

	delete[] A;
	return Buf;
}

int** PopRowBack(int** A, int& rows_A)
{
	int** Buf = new int* [--rows_A];
	for (int i = 0; i < rows_A; i++)
		Buf[i] = A[i];
	delete[] A[rows_A];
	delete[] A;
	return Buf;
}
int** PopRowFront(int** A, int& rows_A)
{
	int** Buf = new int* [--rows_A];
	for (int i = 0; i < rows_A; i++)
		Buf[i] = A[i + 1];
	delete[] A[0];
	delete[] A;
	return Buf;
}
int** EraseRow(int** A, int& rows_A, int index_Row)
{
	int** Buf = new int* [rows_A - 1];
	for (int i = 0; i < rows_A; i++)
		if (i < index_Row)
			Buf[i] = A[i];
		else if (i > index_Row)
			Buf[i - 1] = A[i];
	rows_A--;
	delete[] A[index_Row];
	delete[] A;
	return Buf;
}

int** PushColBack(int** A, int rows_A, int& cols_A, int* B)
{
	int** Buf = new int* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new int[cols_A + 1];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j] = A[i][j];
		Buf[i][cols_A] = B[i];
		delete[] A[i];
	}
	cols_A++;
	delete[] A;
	return Buf;
}
int** PushColFront(int** A, int rows_A, int& cols_A, int* B)
{
	int** Buf = new int* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new int[cols_A + 1];
		Buf[i][0] = B[i];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j + 1] = A[i][j];
		delete[] A[i];
	}
	cols_A++;
	delete[] A;
	return Buf;
}
int** InsertCol(int** A, int rows_A, int& cols_A, int* B, int index_Col)
{
	int** Buf = new int* [rows_A];
	cols_A++;
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new int[cols_A];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j] = (j < index_Col ? A[i][j] :
				j > index_Col ? A[i][j - 1] : B[i]);
		delete[] A[i];
	}
	delete[] A;
	return Buf;
}

int** PopColBack(int** A, int rows_A, int& cols_A)
{
	cols_A--;
	int** Buf = new int* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new int[cols_A];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j] = A[i][j];
		delete[] A[i];
	}
	delete[] A;
	return Buf;
}
int** PopColFront(int** A, int rows_A, int& cols_A)
{
	cols_A--;
	int** Buf = new int* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new int[cols_A];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j] = A[i][j + 1];
		delete[] A[i];
	}
	delete[] A;
	return Buf;
}
int** EraseCol(int** A, int rows_A, int& cols_A, int index_Col)
{
	int** Buf = new int* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new int[cols_A - 1];
		for (int j = 0; j < cols_A; j++)
			if (j < index_Col) Buf[i][j] = A[i][j];
			else if (j > index_Col)
				Buf[i][j - 1] = A[i][j];
		delete[] A[i];
	}
	cols_A--;
	delete[] A;
	return Buf;
}