//PushAndPop.cpp
#include "PushAndPop.h"

template <typename T> T* Insert(T* A, int& size_A, T element, int index)
{
	T* Buf = new T[++size_A];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = (i < index ? *(A + i) :
			(i > index ? *(A + i - 1) : element));
	delete[] A;
	return Buf;
}
template <typename T> T* Erase(T* A, int& size_A, int index)
{
	T* Buf = new T[size_A - 1];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = (i < index ? *(A + i) : *(A + i + 1));
	size_A--;
	delete[] A;
	return Buf;
}

template <typename T> T* PushBack(T* A, int& size_A, T element)
{
	T* Buf = new T[size_A + 1];
	for (int i = 0; i < size_A; i++)
		*(Buf + i) = *(A + i);
	*(Buf + size_A) = element;
	size_A++;
	delete[] A;
	return Buf;
}
template <typename T> T* PushFront(T* A, int& size_A, T element)
{
	T* Buf = new T[++size_A];
	*Buf = element;
	for (int i = 1; i < size_A; i++)
		*(Buf + i) = *(A + i - 1);
	delete[] A;
	return Buf;
}

template <typename T> T* PopBack(T* A, int& size_A)
{
	T* Buf = new T[--size_A];
	for (int i = 0; i < size_A; i++) *(Buf + i) = *(A + i);
	delete[] A;
	return Buf;
}
template <typename T> T* PopFront(T* A, int& size_A)
{
	T* Buf = new T[--size_A];
	for (int i = 0; i < size_A; i++) *(Buf + i) = *(A + i + 1);
	delete[] A;
	return Buf;
}


template <typename T> T** Allocate(int rows_A, int cols_A)
{
	T** Buf = new T* [rows_A];
	for (int i = 0; i < rows_A; i++)
		Buf[i] = new T[cols_A];
	return Buf;
}
template <typename T> void Clear(T** A, int rows_A) 
{
	for (int i = 0; i < rows_A; i++)
		delete[] A[i];
	delete[] A;
}

template <typename T> T** InsertRow(T** A, int& rows_A, int cols_A, T* B, int index_Row)
{
	T** Buf = new T* [++rows_A];
	Buf[index_Row] = new T[cols_A];
	for (int j = 0; j < cols_A; j++)
		Buf[index_Row][j] = B[j];
	for (int i = 0; i < rows_A; i++)
		if (i != index_Row)
			Buf[i] = (i < index_Row ? A[i] : A[i - 1]);

	delete[] A;
	return Buf;
}
template <typename T> T** PushRowBack(T** A, int& rows_A, int cols_A, T* B)
{
	T** Buf = new T* [rows_A + 1];
	Buf[rows_A++] = new T[cols_A];
	for (int i = 0; i < rows_A - 1; i++)
		Buf[i] = A[i];
	for (int j = 0; j < cols_A; j++)
		Buf[rows_A - 1][j] = B[j];
	delete[] A;
	return Buf;
}
template <typename T> T** PushRowFront(T** A, int& rows_A, int cols_A, T* B)
{
	T** Buf = new T* [++rows_A];
	Buf[0] = new T[cols_A];
	for (int j = 0; j < cols_A; j++)
		Buf[0][j] = B[j];
	for (int i = 1; i < rows_A; i++)
		Buf[i] = A[i - 1];
	delete[] A;
	return Buf;
}

template <typename T> T** EraseRow(T** A, int& rows_A, int index_Row)
{
	T** Buf = new T* [rows_A - 1];
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
template <typename T> T** PopRowBack(T** A, int& rows_A)
{
	T** Buf = new T* [--rows_A];
	for (int i = 0; i < rows_A; i++)
		Buf[i] = A[i];
	delete[] A[rows_A];
	delete[] A;
	return Buf;
}
template <typename T> T** PopRowFront(T** A, int& rows_A)
{
	T** Buf = new T* [--rows_A];
	for (int i = 0; i < rows_A; i++)
		Buf[i] = A[i + 1];
	delete[] A[0];
	delete[] A;
	return Buf;
}

template <typename T> T** InsertCol(T** A, int rows_A, int& cols_A, T* B, int index_Col)
{
	T** Buf = new T* [rows_A];
	cols_A++;
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new T[cols_A];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j] = (j < index_Col ? A[i][j] :
				j > index_Col ? A[i][j - 1] : B[i]);
		delete[] A[i];
	}
	delete[] A;
	return Buf;
}
template <typename T> T** PushColBack(T** A, int rows_A, int& cols_A, T* B)
{
	T** Buf = new T* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new T[cols_A + 1];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j] = A[i][j];
		Buf[i][cols_A] = B[i];
		delete[] A[i];
	}
	cols_A++;
	delete[] A;
	return Buf;
}
template <typename T> T** PushColFront(T** A, int rows_A, int& cols_A, T* B)
{
	T** Buf = new T* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new T[cols_A + 1];
		Buf[i][0] = B[i];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j + 1] = A[i][j];
		delete[] A[i];
	}
	cols_A++;
	delete[] A;
	return Buf;
}

template <typename T> T** EraseCol(T** A, int rows_A, int& cols_A, int index_Col)
{
	T** Buf = new T* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new T[cols_A - 1];
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
template <typename T> T** PopColBack(T** A, int rows_A, int& cols_A)
{
	cols_A--;
	T** Buf = new T* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new T[cols_A];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j] = A[i][j];
		delete[] A[i];
	}
	delete[] A;
	return Buf;
}
template <typename T> T** PopColFront(T** A, int rows_A, int& cols_A)
{
	cols_A--;
	T** Buf = new T* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		Buf[i] = new T[cols_A];
		for (int j = 0; j < cols_A; j++)
			Buf[i][j] = A[i][j + 1];
		delete[] A[i];
	}
	delete[] A;
	return Buf;
}